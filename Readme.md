# BaseConverter
## Version History
See changelog.md.
## License
See LICENSE.
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
0 - OK  
1 - No Arguments  
2 - Invalid Arguments  
3 - Base Too Large For Automatic Digits  
4 - Not Enough Digits For Base  
5 - Couldn't Allocate Memory For Digits  
6 - Couldn't Allocate Memory For Output  
