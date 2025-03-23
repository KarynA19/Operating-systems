cc Standard_shell.c -o Standard_shell
cc Math.c -o Math
cc Math_Shell.c -o Math_Shell
cc Sqrt.c -o Sqrt -lm
cc Power.c -o Power -lm
cc Solve.c -o Solve -lm
cc History.c -o History
cc Logic.c -o Logic
cc Logic_Shell.c -o Logic_Shell
cc Highbit.c -o Highbit -lm
cc DectoBin.c -o DectoBin -lm
cc DectoHex.c -o DectoHex -lm
cc String.c -o String
cc String_Shell.c -o String_Shell
cc PrintFile.c -o PrintFile
cc Find.c -o Find
cc Replace.c -o Replace
cc exit.c -o exit
./Standard_shell $1 $2 $3