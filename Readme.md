# BaseConverter
The version history can be found in [the file named changelog.md](https://github.com/benjidial/BaseConverter/blob/master/changelog.md).  Any contributions to this source would be welcome.  If you would like to contribute, you can fork [the repository](https://github.com/benjidial/BaseConverter), make fixes or additions there, and then submit a pull request.  If you would like to report a bug, you can do so [here](https://github.com/benjidial/BaseConverter/issues).  This is under the MIT License.  The full text can be found in [the file named LICENSE in this directory](https://github.com/benjidial/BaseConverter/blob/master/LICENSE), or online [here](http://opensource.org/licenses/MIT).
## BaseConverter --help
```
Help for BaseConverter
Command Line:
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

  Examples:
    BaseConverter 1729 6
    BaseConverter 42 16
    BaseConverter 10 2 O|
    BaseConverter 126 12 0123456789XE ;


Return Values:
  0   OK  
  1   No Arguments  
  2   Invalid Arguments  
  3   Base Too Large For Automatic Digits  
  4   Not Enough Digits For Base  
  5   Couldn't Allocate Memory For Digits  
  6   Couldn't Allocate Memory For Output  
```
