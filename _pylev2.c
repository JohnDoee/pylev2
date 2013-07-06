#include <Python.h>

int _levenshtein(wchar_t *str1, wchar_t *str2, int threshold) {
  int str1_len = wcslen(str1);
  int str2_len = wcslen(str2);
  
  if (str1_len == 0) {
    return (threshold != -1 && threshold < str2_len) ? -1 : str2_len;
  }
  
  if (str2_len == 0)
    return (threshold != -1 && threshold < str1_len) ? -1 : str1_len;
  
  int diagonals = str1_len + str2_len + 1;
  int max_diagonal = (((str1_len < str2_len) ? str1_len : str2_len) + 1) * 2;
  int buff[max_diagonal];
  int prev_min = INT_MAX;
  int head = 0;
  int tail = 0;
  int val = 0;
  
  int i, x, y, a, b, c, diagonal_min, cost;
  for (i = 0; i < diagonals; i++) {
    x = (i < str1_len) ? i : str1_len;
    y = (i < x) ? 0 : i-x;
    diagonal_min = INT_MAX;
    
    while (x >= 0 && y <= str2_len) {
      if (x > 0 && y > 0) {
        cost = (str1[x-1] != str2[y-1]) ? 1 : 0;
        a = buff[tail];
        tail = (tail+1) % max_diagonal;
        b = buff[tail];
        tail = (tail+1) % max_diagonal;
        c = buff[tail];
        
        if (y == str2_len)
          tail = (tail+1) % max_diagonal;
        
        if (x != str1_len) {
          buff[head] = a;
          head = (head+1) % max_diagonal;
        }
        a++; c++;
        b = b + cost;
        val = (a < b && a < c) ? a : ((b < c) ? b : c);
      } else if (x == 0 && y == 0) {
        val = 0;
      } else if (x > 0 && y == 0) {
        val = buff[tail] + 1;
      } else if (x == 0 && y > 0) {
        a = buff[tail];
        tail = (tail+1) % max_diagonal;
        buff[head] = a;
        head = (head+1) % max_diagonal;
        val = a + 1;
      }
      
      buff[head] = val;
      head = (head+1) % max_diagonal;
      
      if (diagonal_min > val)
        diagonal_min = val;
      
      x--;
      y++;
    }
    
    if (threshold > -1 && diagonal_min > threshold && prev_min > threshold) //  &&  && 
      return -1;
    
    prev_min = diagonal_min;
  }
  
  if (threshold > -1 && buff[tail] > threshold)
    return -1;
  
  return buff[tail];
}


static PyObject* levenshtein(PyObject* self, PyObject* args)
{
    wchar_t *str1, *str2;
    int threshold = -1;
    if (!PyArg_ParseTuple(args, "uu|i:levenshtein", &str1, &str2, &threshold))
      return NULL;
    
    int distance = _levenshtein(str1, str2, threshold);
    if (distance < 0) {
      Py_INCREF(Py_None);
      return Py_None;
    }
    
    return Py_BuildValue("i", distance);
}

static char levenshtein_docs[] =
    "levenshtein(str_1, str_2, threshold): Get that distance!!\n";

static PyMethodDef levenshtein_funcs[] = {
    {"levenshtein", (PyCFunction)levenshtein,
     METH_VARARGS, levenshtein_docs},
    {NULL}
};

void init_pylev2(void)
{
    Py_InitModule3("_pylev2", levenshtein_funcs,
                   "Calculate levenhstein distance.");
}
 