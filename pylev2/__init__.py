import _pylev2

def levenshtein(str_1, str_2, threshold=None):
    """
    Calculates the Levenshtein distance between two strings, supports threshold.

    Usage::

        >>> levenshtein('kitten', 'sitting')
        3
        >>> levenshtein('kitten', 'kitten')
        0
        >>> levenshtein('', '')
        0
        >>> levenshtein('pretty horses', 'ugly duckling', threshold=2)
        None

    """
    if not isinstance(str_1, unicode):
        str_1 = unicode(str_1)
    
    if not isinstance(str_2, unicode):
        str_2 = unicode(str_2)
    
    if threshold is not None:
        return _pylev2.levenshtein(str_1, str_2, threshold)
    return _pylev2.levenshtein(str_1, str_2)