pylev2
======

A Levenshtein implementation with a premissive license.
Intended to be a semi-dropin replacement for pylev and to be faster by leveraging a C extension.

Requirements
------------

* C compiler
* Only tested with Python 2.7

Usage
-----

Simple example.::

    import pylev2
    distance = pylev2.levenshtein('kittens', 'sitting')
    assert(distance, 3)

Changing from pylev to pylev2
-----------------------------

Replace all instances of pylev with pylev2, please note that pylev2 does not support
the functions with spelling errors or the classic version.

Tests
-----

Setup::

    $ virtualenv .env
    $ .env/bin/pip install git+https://github.com/JohnDoee/pylev2.git

Running::

    $ python -m unittest pylev2.tests


License
--------
MIT, see LICENSE

History
-------

Uses semantic versioning

* v1.0.0-beta

    * Initial release.