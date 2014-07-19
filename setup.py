#!/usr/bin/env python

from distutils.core import setup, Extension

module1 = Extension('_pylev2', sources = ['_pylev2.c'])

setup(name='pylev2',
      version='1.0.0',
      description='A Levenshtein implementation with a premissive license.',
      long_description=open('README.rst').read(),
      author='Anders Jensen',
      license='MIT',
      author_email='johndoee+pylev2@tidalstream.org',
      url='https://github.com/JohnDoee/pylev2/',
      packages=['pylev2'],
      classifiers=[
        'Development Status :: 4 - Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: Python',
        'Topic :: Software Development :: Libraries :: Python Modules',
    ],
    ext_modules = [module1]
)

