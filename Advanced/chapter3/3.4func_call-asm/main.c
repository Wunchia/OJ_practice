#include <stdio.h>
int add(int a,int b){
    int  ret;
    ret=a+b;
    return ret;
}

int main() {
    int a,b,ret;
    int *p;
    a=5;
    p=&a;
    b=*p+2;
    ret=add(a,b);
    printf("add result=%d\n",ret);
    return 0;
}
//gcc main.c -o main.exe
//objdump --source main.exe > main.dump

//0000000000401550 <add>:
//401550:	55                   	push   %rbp
//401551:	48 89 e5             	mov    %rsp,%rbp
//401554:	48 83 ec 10          	sub    $0x10,%rsp
//401558:	89 4d 10             	mov    %ecx,0x10(%rbp)
//40155b:	89 55 18             	mov    %edx,0x18(%rbp)
//40155e:	8b 55 10             	mov    0x10(%rbp),%edx
//401561:	8b 45 18             	mov    0x18(%rbp),%eax
//401564:	01 d0                	add    %edx,%eax
//401566:	89 45 fc             	mov    %eax,-0x4(%rbp)
//401569:	8b 45 fc             	mov    -0x4(%rbp),%eax
//40156c:	48 83 c4 10          	add    $0x10,%rsp
//401570:	5d                   	pop    %rbp
//401571:	c3                   	retq
//
//0000000000401572 <main>:
//401572:	55                   	push   %rbp
//401573:	48 89 e5             	mov    %rsp,%rbp
//401576:	48 83 ec 40          	sub    $0x40,%rsp
//40157a:	e8 01 01 00 00       	callq  401680 <__main>
//40157f:	c7 45 ec 05 00 00 00 	movl   $0x5,-0x14(%rbp)
//401586:	48 8d 45 ec          	lea    -0x14(%rbp),%rax
//40158a:	48 89 45 f8          	mov    %rax,-0x8(%rbp)
//40158e:	48 8b 45 f8          	mov    -0x8(%rbp),%rax
//401592:	8b 00                	mov    (%rax),%eax
//401594:	83 c0 02             	add    $0x2,%eax
//401597:	89 45 f4             	mov    %eax,-0xc(%rbp)
//40159a:	8b 45 ec             	mov    -0x14(%rbp),%eax
//40159d:	8b 55 f4             	mov    -0xc(%rbp),%edx
//4015a0:	89 c1                	mov    %eax,%ecx
//4015a2:	e8 a9 ff ff ff       	callq  401550 <add>     #调用函数add  e8 操作码  a9 ff ff ff地址码
//4015a7:	89 45 f0             	mov    %eax,-0x10(%rbp)
//4015aa:	8b 45 f0             	mov    -0x10(%rbp),%eax
//4015ad:	89 c2                	mov    %eax,%edx
//4015af:	48 8d 0d 4a 2a 00 00 	lea    0x2a4a(%rip),%rcx        # 404000 <.rdata>
//4015b6:	e8 f5 14 00 00       	callq  402ab0 <printf>
//4015bb:	b8 00 00 00 00       	mov    $0x0,%eax
//4015c0:	48 83 c4 40          	add    $0x40,%rsp
//4015c4:	5d                   	pop    %rbp
//4015c5:	c3                   	retq
//4015c6:	90                   	nop
//4015c7:	90                   	nop
//4015c8:	90                   	nop
//4015c9:	90                   	nop
//4015ca:	90                   	nop
//4015cb:	90                   	nop
//4015cc:	90                   	nop
//4015cd:	90                   	nop
//4015ce:	90                   	nop
//4015cf:	90                   	nop