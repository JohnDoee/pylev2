import unittest
import pylev2

class LevenshteinTestCase(unittest.TestCase):
    def test_basic(self):
        self.assertEqual(pylev2.levenshtein('abc', 'abc'), 0)
    
    def test_empty(self):
        self.assertEqual(pylev2.levenshtein('', ''), 0)
    
    def test_mixed_type(self):
        self.assertEqual(pylev2.levenshtein(u'\u2603', 'e'), 1)
    
    def test_unicode(self):
        self.assertEqual(pylev2.levenshtein(u'\u2603', u'\u2603'), 0)
    
    def test_something(self):
        self.assertEqual(pylev2.levenshtein(u'kittens', u'sitting'), 3)
    
    def test_threshold(self):
        self.assertEqual(pylev2.levenshtein(u'', u'aaa', 3), 3)
        self.assertEqual(pylev2.levenshtein(u'', u'aaa', 2), None)