a ^ a = 0;
(a ^ b) ^ c = a ^ (b ^ c);
a ^ b = b ^ a;

state machine (single number II)
bool logic circuit

int lowbit = a & ~(a-1);
int lowbit = a & (-a);

bool powerOfTwo = ((n & (n-1)) == 0);

//http://blog.csdn.net/nicky_zs/article/details/4053146
operator priority

() [] -> . ::
++ --(post)

! ~
++ --(pre)
+/-(sign)
*p &a
(long)
sizeof()

* / %
+ -

<< >> (bit shift)

< <= > >=

== !=

& ^ | 

&& || 

=

,

算术 移位 比较 位运算 逻辑