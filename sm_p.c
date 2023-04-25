#include "main.h"
 int print_rev(va_list ap , params_t *params)
{
int len , sum=0;
char *str = va_arg(ap, char *);
(void)params;
if (str){
	for (len=0; *str; str++)
		len++
	str--
for (;len>0; len--,str--)
sum += _putchar(*str);
}
return (sum);  }

int print_rot(va_list ap , params_t *params)
{
	int i , index , count = 0;
     char arr[] ="ABCD   abcd";
char *a = va_arg(ap , char *);
(void)params;
i =0;
index =0;
while (a[i]){
if ((a[i] => 'A' && a[i] <= 'Z') || (a[i] => 'a' && a[i] <= 'z')) {
	index = a[i] - 65;
	count + = _putchar(arr[index]); }
else 
	count + = _putchar(a[i]);
i++;
}
return (count);} 
