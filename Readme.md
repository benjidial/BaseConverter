# BaseConverter
## Version History
See <changelog.md>.
## License
```
The MIT License (MIT)

Copyright (c) 2015 Benji Dial

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```
## Command Line Help
```
Help for BaseConverter
  BaseConverter dec base [digits [decimalpoint]]
  BaseConverter --help

  --help  Outputs this help text.
  dec     This is the decimal input.
  base    This is the base to convert it to.
  digits  These are the digits for the base.
          If not supplied, the following will be used:
          0123456789abcdefghijklmnopqrstuvwxyz
  decimalpoint  This goes after the unit digit.
                If not specified, '.' is used.
```
## Return Values
0   OK  
1   No Arguments  
2   Invalid Arguments  
3   Base Too Large For Automatic Digits  
4   Not Enough Digits For Base  
5   Couldn't Allocate Memory For Digits  
6   Couldn't Allocate Memory For Output  
