/*
Alphabet		ASCII		Binary of ascii
--------		-----		---------------
a			97			1100001
A			65			1000001

b			98			1100010
B			66			1000010

c			99			1100011
C			67			1000011


p			112			1110000
P			80			1010000

q			113			1110001
Q			81			1010001

r			114			1110010
R			82			1010010

s			115			1110011
S			83			1010011

t			116			1110100
T			84			1010100

u			117			1110101
U			85			1010101

v			118			1110110
V			86			1010110

w			119			1110111
W			87			1010111

x			120			1111000
X			88			1011000

y			121			1111001
Y			89			1011001

z			122			1111010
Z			90			1011010
			
1)By observing above pattern,for every alphabet the 5th LSB bit of upper case and lower case is toggled.So,to convert lower to upper and viceversa we should toggle the
5th bit.
2)To toggle 5th  we should xor a number with 100000(i.e 1<<5 ) whose corresponding charecter value is whitespace(" ")

*/
char convert(char letter)
{
	return letter ^ ' ';
}
