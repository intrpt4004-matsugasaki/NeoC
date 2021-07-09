# NeoC
Neo C Programming Environment Library

![](https://user-images.githubusercontent.com/85844095/125081210-b6ea7380-e100-11eb-9f34-0871e29de9cc.png)
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;__↑↑↑ examples/Theme.c ↑↑↑__

&emsp;&emsp;&emsp;__↓↓↓ Sample Code (examples/SampleCode.c) ↓↓↓__
```C
#include "NeoC/String.h"
#include "NeoC/Console.h"
#include "NeoC/Exception.h"

void main() $NeoC {
   String_t *text = String.New("NeoC is a Neo C Programming Environment Library !");
   Console.WriteLine(text);

   try {
      int32_t fm = String.FirstIndexOf(text, 'i');
      int32_t lm = String.LastIndexOf(text, 'i');

      for (int32_t i = 0; i < String.GetLength(text); i++) {
         Console.WriteChar((i == fm || i == lm)? '^' : ' ');
      }
      Console.NewLine();

   } catch (String.RuntimeException) {
      Console.WriteErrorLine(String.New("[Error] Target Not Found."));
   } end

} NeoC$
```
<br>

## Build
```fish
$ sh build.sh
```
`NeoC/*.h` `NeoC.a`
<br><br>

### Build `examples/*`
```fish
$ sh all.sh
$ cd examples
$ ./XXX
```
