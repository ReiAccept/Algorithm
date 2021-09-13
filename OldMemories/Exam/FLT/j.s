	.file	"j.cpp"
	.section	.text$_ZnwjPv,"x"
	.linkonce discard
	.globl	__ZnwjPv
	.def	__ZnwjPv;	.scl	2;	.type	32;	.endef
__ZnwjPv:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZSt16__deque_buf_sizej,"x"
	.linkonce discard
	.globl	__ZSt16__deque_buf_sizej
	.def	__ZSt16__deque_buf_sizej;	.scl	2;	.type	32;	.endef
__ZSt16__deque_buf_sizej:
	pushl	%ebp
	movl	%esp, %ebp
	cmpl	$511, 8(%ebp)
	ja	L4
	movl	$512, %eax
	movl	$0, %edx
	divl	8(%ebp)
	jmp	L6
L4:
	movl	$1, %eax
L6:
	popl	%ebp
	ret
.lcomm __ZStL8__ioinit,1,1
	.globl	_visit
	.bss
	.align 32
_visit:
	.space 42875
	.globl	_map
	.align 32
_map:
	.space 42875
	.globl	_l
	.align 4
_l:
	.space 4
	.globl	_r
	.align 4
_r:
	.space 4
	.globl	_c
	.align 4
_c:
	.space 4
	.globl	_q
	.align 32
_q:
	.space 40
	.section	.text$_Z7addnode4node,"x"
	.linkonce discard
	.globl	__Z7addnode4node
	.def	__Z7addnode4node;	.scl	2;	.type	32;	.endef
__Z7addnode4node:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	16(%ebp), %eax
	imull	$35, %ecx, %ecx
	imull	$1225, %edx, %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	addl	$_visit, %eax
	movzbl	(%eax), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L9
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	16(%ebp), %eax
	imull	$35, %ecx, %ecx
	imull	$1225, %edx, %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	addl	$_map, %eax
	movzbl	(%eax), %eax
	cmpb	$35, %al
	je	L9
	movl	8(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	16(%ebp), %eax
	imull	$35, %ecx, %ecx
	imull	$1225, %edx, %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	addl	$_visit, %eax
	movb	$1, (%eax)
	leal	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_
	subl	$4, %esp
L9:
	nop
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Escaped in %d minute(s).\12\0"
LC1:
	.ascii "Trapped!\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$84, %esp
	call	___main
L36:
	movl	$_l, (%esp)
	movl	$__ZSt3cin, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$_r, (%esp)
	movl	%eax, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	$_c, (%esp)
	movl	%eax, %ecx
	call	__ZNSirsERi
	subl	$4, %esp
	movl	(%eax), %edx
	subl	$12, %edx
	movl	(%edx), %edx
	addl	%edx, %eax
	movl	%eax, %ecx
	call	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv
	testl	%eax, %eax
	je	L11
	movl	_l, %eax
	testl	%eax, %eax
	jne	L12
	movl	_r, %eax
	testl	%eax, %eax
	jne	L12
	movl	_c, %eax
	testl	%eax, %eax
	je	L11
L12:
	movl	$1, %eax
	jmp	L13
L11:
	movl	$0, %eax
L13:
	testb	%al, %al
	je	L14
L16:
	movl	$_q, %ecx
	call	__ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv
	xorl	$1, %eax
	testb	%al, %al
	je	L15
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv
	jmp	L16
L15:
	movl	$42875, 8(%esp)
	movl	$0, 4(%esp)
	movl	$_visit, (%esp)
	call	_memset
	movl	$42875, 8(%esp)
	movl	$46, 4(%esp)
	movl	$_map, (%esp)
	call	_memset
	movb	$0, -9(%ebp)
	movl	$0, -16(%ebp)
L25:
	movl	_l, %eax
	cmpl	%eax, -16(%ebp)
	jge	L17
	movl	$0, -20(%ebp)
L24:
	movl	_r, %eax
	cmpl	%eax, -20(%ebp)
	jge	L18
	movl	$0, -24(%ebp)
L23:
	movl	_c, %eax
	cmpl	%eax, -24(%ebp)
	jge	L19
	movl	-20(%ebp), %eax
	imull	$35, %eax, %edx
	movl	-16(%ebp), %eax
	imull	$1225, %eax, %eax
	addl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	addl	$_map, %eax
	movl	%eax, 4(%esp)
	movl	$__ZSt3cin, (%esp)
	call	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_
	movl	(%eax), %edx
	subl	$12, %edx
	movl	(%edx), %edx
	addl	%edx, %eax
	movl	%eax, %ecx
	call	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv
	testl	%eax, %eax
	je	L20
	movl	-20(%ebp), %edx
	movl	-16(%ebp), %eax
	imull	$35, %edx, %edx
	imull	$1225, %eax, %eax
	addl	%eax, %edx
	movl	-24(%ebp), %eax
	addl	%edx, %eax
	addl	$_map, %eax
	movzbl	(%eax), %eax
	cmpb	$83, %al
	jne	L20
	movl	$1, %eax
	jmp	L21
L20:
	movl	$0, %eax
L21:
	testb	%al, %al
	je	L22
	movl	-16(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	-20(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	-24(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	$0, -28(%ebp)
L22:
	addl	$1, -24(%ebp)
	jmp	L23
L19:
	addl	$1, -20(%ebp)
	jmp	L24
L18:
	addl	$1, -16(%ebp)
	jmp	L25
L17:
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_
	subl	$4, %esp
	movl	-40(%ebp), %edx
	movl	-36(%ebp), %ecx
	movl	-32(%ebp), %eax
	imull	$35, %ecx, %ecx
	imull	$1225, %edx, %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	addl	$_visit, %eax
	movb	$1, (%eax)
L34:
	movl	$_q, %ecx
	call	__ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv
	xorl	$1, %eax
	testb	%al, %al
	je	L26
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5frontEv
	movl	(%eax), %edx
	movl	%edx, -56(%ebp)
	movl	4(%eax), %edx
	movl	%edx, -52(%ebp)
	movl	8(%eax), %edx
	movl	%edx, -48(%ebp)
	movl	12(%eax), %eax
	movl	%eax, -44(%ebp)
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv
	movl	-56(%ebp), %edx
	movl	-52(%ebp), %ecx
	movl	-48(%ebp), %eax
	imull	$35, %ecx, %ecx
	imull	$1225, %edx, %edx
	addl	%ecx, %edx
	addl	%edx, %eax
	addl	$_map, %eax
	movzbl	(%eax), %eax
	cmpb	$69, %al
	jne	L27
	movl	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movb	$1, -9(%ebp)
	jmp	L26
L27:
	movl	-44(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -44(%ebp)
	movl	-56(%ebp), %eax
	subl	$1, %eax
	testl	%eax, %eax
	js	L28
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-72(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -72(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
L28:
	movl	-56(%ebp), %eax
	leal	1(%eax), %edx
	movl	_l, %eax
	cmpl	%eax, %edx
	jge	L29
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-72(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -72(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
L29:
	movl	-52(%ebp), %eax
	subl	$1, %eax
	testl	%eax, %eax
	js	L30
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-68(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -68(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
L30:
	movl	-52(%ebp), %eax
	leal	1(%eax), %edx
	movl	_r, %eax
	cmpl	%eax, %edx
	jge	L31
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-68(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -68(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
L31:
	movl	-48(%ebp), %eax
	subl	$1, %eax
	testl	%eax, %eax
	js	L32
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-64(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -64(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
L32:
	movl	-48(%ebp), %eax
	leal	1(%eax), %edx
	movl	_c, %eax
	cmpl	%eax, %edx
	jge	L34
	movl	-56(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	-52(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	-48(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	-44(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	-64(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -64(%ebp)
	movl	-72(%ebp), %eax
	movl	%eax, (%esp)
	movl	-68(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-64(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-60(%ebp), %eax
	movl	%eax, 12(%esp)
	call	__Z7addnode4node
	jmp	L34
L26:
	movzbl	-9(%ebp), %eax
	xorl	$1, %eax
	testb	%al, %al
	je	L36
	movl	$LC1, (%esp)
	call	_puts
	jmp	L36
L14:
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EEC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EEC1Ev
	.def	__ZNSt5dequeI4nodeSaIS0_EEC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EEC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev
	nop
	leave
	ret
	.def	___gxx_personality_sj0;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Register;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Unregister;	.scl	2;	.type	32;	.endef
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EED1Ev
	.def	__ZNSt5dequeI4nodeSaIS0_EED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EED1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	%ecx, -60(%ebp)
	movl	$___gxx_personality_sj0, -88(%ebp)
	movl	$LLSDA1480, -84(%ebp)
	leal	-80(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L41, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-60(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, -116(%ebp)
	leal	-56(%ebp), %eax
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	movl	$1, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE3endEv
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	-60(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE5beginEv
	subl	$4, %esp
	movl	-60(%ebp), %eax
	movl	-116(%ebp), %esi
	movl	%esi, 8(%esp)
	leal	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-40(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE15_M_destroy_dataESt15_Deque_iteratorIS0_RS0_PS0_ES6_RKS1_
	subl	$12, %esp
	movl	-60(%ebp), %eax
	movl	$-1, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev
	jmp	L43
L41:
	leal	24(%ebp), %ebp
	movl	-104(%ebp), %eax
	movl	%eax, -116(%ebp)
	movl	-60(%ebp), %eax
	movl	$0, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -108(%ebp)
	call	__Unwind_SjLj_Resume
L43:
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1480:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1480-LLSDACSB1480
LLSDACSB1480:
	.uleb128 0
	.uleb128 0
LLSDACSE1480:
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EED1Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEEC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEEC1ERKS3_
	.def	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEEC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEEC1ERKS3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_
	subl	$4, %esp
	nop
	leave
	ret	$4
	.section	.text$_ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_
	.def	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE4pushERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE9push_backERKS0_
	subl	$4, %esp
	nop
	leave
	ret	$4
	.section	.text$_ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv
	.def	__ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv;	.scl	2;	.type	32;	.endef
__ZNKSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5emptyEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt5dequeI4nodeSaIS0_EE5emptyEv
	leave
	ret
	.section	.text$_ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv
	.def	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv;	.scl	2;	.type	32;	.endef
__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE3popEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE9pop_frontEv
	nop
	leave
	ret
	.section	.text$_ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5frontEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5frontEv
	.def	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5frontEv;	.scl	2;	.type	32;	.endef
__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEE5frontEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE5frontEv
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaI4nodeED2Ev
	nop
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	%ecx, -28(%ebp)
	movl	$___gxx_personality_sj0, -56(%ebp)
	movl	$LLSDA1495, -52(%ebp)
	leal	-48(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L54, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-28(%ebp), %eax
	movl	$-1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1Ev
	movl	-28(%ebp), %eax
	movl	$0, (%esp)
	movl	$1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj
	subl	$4, %esp
	jmp	L56
L54:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -76(%ebp)
	call	__Unwind_SjLj_Resume
L56:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1495:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1495-LLSDACSB1495
LLSDACSB1495:
	.uleb128 0
	.uleb128 0
LLSDACSE1495:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EEC2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	%ecx, -28(%ebp)
	movl	$___gxx_personality_sj0, -56(%ebp)
	movl	$LLSDA1498, -52(%ebp)
	leal	-48(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L60, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-28(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	L58
	movl	-28(%ebp), %eax
	movl	36(%eax), %eax
	leal	4(%eax), %ecx
	movl	-28(%ebp), %eax
	movl	20(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	$1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	4(%eax), %ecx
	movl	-28(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j
	subl	$8, %esp
L58:
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev
	jmp	L62
L60:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -76(%ebp)
	call	__Unwind_SjLj_Resume
L62:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1498:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1498-LLSDACSB1498
LLSDACSB1498:
	.uleb128 0
	.uleb128 0
LLSDACSE1498:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev,"x"
	.linkonce discard
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE5beginEv
	.def	__ZNSt5dequeI4nodeSaIS0_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE5beginEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	ret	$4
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE3endEv
	.def	__ZNSt5dequeI4nodeSaIS0_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE3endEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	ret	$4
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	.def	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 12(%eax)
	nop
	leave
	ret	$4
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE15_M_destroy_dataESt15_Deque_iteratorIS0_RS0_PS0_ES6_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE15_M_destroy_dataESt15_Deque_iteratorIS0_RS0_PS0_ES6_RKS1_
	.def	__ZNSt5dequeI4nodeSaIS0_EE15_M_destroy_dataESt15_Deque_iteratorIS0_RS0_PS0_ES6_RKS1_;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE15_M_destroy_dataESt15_Deque_iteratorIS0_RS0_PS0_ES6_RKS1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$36, %esp
	movl	%ecx, -36(%ebp)
	nop
	leave
	ret	$12
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_
	.def	__ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$204, %esp
	movl	%ecx, -76(%ebp)
	movl	$___gxx_personality_sj0, -132(%ebp)
	movl	$LLSDA1509, -128(%ebp)
	leal	-124(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L73, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$-1, -152(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt5dequeI4nodeSaIS0_EE4sizeEv
	movl	%eax, -160(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE17_S_select_on_copyERKS2_
	movl	%eax, %edx
	movl	-76(%ebp), %eax
	movl	-160(%ebp), %esi
	movl	%esi, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j
	subl	$8, %esp
	movl	-76(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, -160(%ebp)
	movl	-76(%ebp), %eax
	leal	8(%eax), %edx
	leal	-72(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	leal	-56(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	$1, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNKSt5dequeI4nodeSaIS0_EE3endEv
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt5dequeI4nodeSaIS0_EE5beginEv
	subl	$4, %esp
	leal	-104(%ebp), %eax
	movl	-160(%ebp), %edi
	movl	%edi, 40(%esp)
	leal	-72(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	-56(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	-52(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-48(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-44(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	-40(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-36(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__uninitialized_copy_aISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_ES1_ET0_T_SA_S9_RSaIT1_E
	jmp	L75
L73:
	leal	24(%ebp), %ebp
	movl	-148(%ebp), %eax
	movl	%eax, -160(%ebp)
	movl	-76(%ebp), %eax
	movl	$0, -152(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EED2Ev
	movl	-160(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -152(%ebp)
	call	__Unwind_SjLj_Resume
L75:
	leal	-156(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"w"
LLSDA1509:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1509-LLSDACSB1509
LLSDACSB1509:
	.uleb128 0
	.uleb128 0
LLSDACSE1509:
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EEC1ERKS2_,"x"
	.linkonce discard
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE9push_backERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE9push_backERKS0_
	.def	__ZNSt5dequeI4nodeSaIS0_EE9push_backERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE9push_backERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	24(%eax), %edx
	movl	-12(%ebp), %eax
	movl	32(%eax), %eax
	subl	$16, %eax
	cmpl	%eax, %edx
	je	L77
	movl	-12(%ebp), %eax
	movl	24(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE9constructIS1_EEvRS2_PS1_RKT_
	movl	-12(%ebp), %eax
	movl	24(%eax), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 24(%eax)
	jmp	L79
L77:
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_
	subl	$4, %esp
L79:
	nop
	leave
	ret	$4
	.section	.text$_ZNKSt5dequeI4nodeSaIS0_EE5emptyEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt5dequeI4nodeSaIS0_EE5emptyEv
	.def	__ZNKSt5dequeI4nodeSaIS0_EE5emptyEv;	.scl	2;	.type	32;	.endef
__ZNKSt5dequeI4nodeSaIS0_EE5emptyEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$24, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSteqI4nodeRS0_PS0_EbRKSt15_Deque_iteratorIT_T0_T1_ES9_
	leave
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE9pop_frontEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE9pop_frontEv
	.def	__ZNSt5dequeI4nodeSaIS0_EE9pop_frontEv;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE9pop_frontEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	16(%eax), %eax
	subl	$16, %eax
	cmpl	%eax, %edx
	je	L83
	movl	-12(%ebp), %eax
	movl	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	jmp	L85
L83:
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE16_M_pop_front_auxEv
L85:
	nop
	leave
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE5frontEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE5frontEv
	.def	__ZNSt5dequeI4nodeSaIS0_EE5frontEv;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE5frontEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	leal	-24(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE5beginEv
	subl	$4, %esp
	leal	-24(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1Ev
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaI4nodeEC2Ev
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev
	movl	-12(%ebp), %eax
	addl	$24, %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev
	nop
	leave
	ret
	.section	.text$_ZNSaI4nodeED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaI4nodeED2Ev
	.def	__ZNSaI4nodeED2Ev;	.scl	2;	.type	32;	.endef
__ZNSaI4nodeED2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeED2Ev
	nop
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$124, %esp
	movl	%ecx, -60(%ebp)
	movl	$___gxx_personality_sj0, -88(%ebp)
	movl	$LLSDA1522, -84(%ebp)
	leal	-80(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L93, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	movl	%eax, %edi
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	%edi
	addl	$1, %eax
	movl	%eax, -28(%ebp)
	movl	-28(%ebp), %eax
	addl	$2, %eax
	movl	%eax, -44(%ebp)
	movl	$8, -40(%ebp)
	leal	-44(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-40(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-60(%ebp), %eax
	movl	4(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, (%esp)
	movl	$-1, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj
	subl	$4, %esp
	movl	%eax, %edx
	movl	-60(%ebp), %eax
	movl	%edx, (%eax)
	movl	-60(%ebp), %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	4(%eax), %eax
	subl	-28(%ebp), %eax
	shrl	%eax
	sall	$2, %eax
	addl	%edx, %eax
	movl	%eax, -32(%ebp)
	movl	-28(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-32(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -36(%ebp)
	movl	-60(%ebp), %eax
	movl	-36(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, (%esp)
	movl	$1, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_
	subl	$8, %esp
	movl	-60(%ebp), %eax
	leal	8(%eax), %edx
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -108(%ebp)
	movl	%edx, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-36(%ebp), %eax
	leal	-4(%eax), %edx
	movl	-60(%ebp), %eax
	addl	$24, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-60(%ebp), %eax
	movl	12(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	-60(%ebp), %eax
	movl	28(%eax), %eax
	movl	%eax, -116(%ebp)
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	$0, %edx
	divl	%ecx
	movl	%edx, %eax
	sall	$4, %eax
	movl	-116(%ebp), %esi
	leal	(%esi,%eax), %edx
	movl	-60(%ebp), %eax
	movl	%edx, 24(%eax)
	jmp	L96
L93:
	leal	24(%ebp), %ebp
	movl	-104(%ebp), %edx
	movl	-108(%ebp), %eax
	testl	%eax, %eax
	je	L94
	subl	$1, %eax
	testl	%eax, %eax
	je	L95
	subl	$1, %eax
	ud2
L94:
	movl	%edx, %eax
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-60(%ebp), %eax
	movl	4(%eax), %ecx
	movl	-60(%ebp), %eax
	movl	(%eax), %edx
	movl	-60(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	$2, -108(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j
	subl	$8, %esp
	movl	-60(%ebp), %eax
	movl	$0, (%eax)
	movl	-60(%ebp), %eax
	movl	$0, 4(%eax)
	call	___cxa_rethrow
L95:
	movl	%edx, -116(%ebp)
	movl	$0, -108(%ebp)
	call	___cxa_end_catch
	movl	-116(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -108(%ebp)
	call	__Unwind_SjLj_Resume
L96:
	leal	-112(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1522:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1522-LLSDATTD1522
LLSDATTD1522:
	.byte	0x1
	.uleb128 LLSDACSE1522-LLSDACSB1522
LLSDACSB1522:
	.uleb128 0
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0
LLSDACSE1522:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1522:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj,"x"
	.linkonce discard
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	movl	%ecx, -28(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, -12(%ebp)
L99:
	movl	-12(%ebp), %eax
	cmpl	12(%ebp), %eax
	jnb	L100
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_
	subl	$4, %esp
	addl	$4, -12(%ebp)
	jmp	L99
L100:
	nop
	leave
	ret	$8
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	%ecx, -44(%ebp)
	movl	$___gxx_personality_sj0, -72(%ebp)
	movl	$LLSDA1524, -68(%ebp)
	leal	-64(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L103, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	leal	-25(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -92(%ebp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE10deallocateERS3_PS2_j
	leal	-25(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP4nodeED1Ev
	jmp	L105
L103:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %eax
	movl	%eax, -100(%ebp)
	leal	-25(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP4nodeED1Ev
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__Unwind_SjLj_Resume
L105:
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$8
	.section	.gcc_except_table,"w"
LLSDA1524:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1524-LLSDACSB1524
LLSDACSB1524:
	.uleb128 0
	.uleb128 0
LLSDACSE1524:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j,"x"
	.linkonce discard
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE17_S_select_on_copyERKS2_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE17_S_select_on_copyERKS2_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE17_S_select_on_copyERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE17_S_select_on_copyERKS2_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	.def	__ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	leave
	ret
	.section	.text$_ZNKSt5dequeI4nodeSaIS0_EE4sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt5dequeI4nodeSaIS0_EE4sizeEv
	.def	__ZNKSt5dequeI4nodeSaIS0_EE4sizeEv;	.scl	2;	.type	32;	.endef
__ZNKSt5dequeI4nodeSaIS0_EE4sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$24, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZStmiI4nodeRS0_PS0_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS7_SA_
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	%ecx, -28(%ebp)
	movl	$___gxx_personality_sj0, -56(%ebp)
	movl	$LLSDA1530, -52(%ebp)
	leal	-48(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L114, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-28(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1ERKS1_
	subl	$4, %esp
	movl	-28(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	$1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_initialize_mapEj
	subl	$4, %esp
	jmp	L116
L114:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implD1Ev
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -76(%ebp)
	call	__Unwind_SjLj_Resume
L116:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$8
	.section	.gcc_except_table,"w"
LLSDA1530:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1530-LLSDACSB1530
LLSDACSB1530:
	.uleb128 0
	.uleb128 0
LLSDACSE1530:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EEC2ERKS1_j,"x"
	.linkonce discard
	.section	.text$_ZNKSt5dequeI4nodeSaIS0_EE5beginEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt5dequeI4nodeSaIS0_EE5beginEv
	.def	__ZNKSt5dequeI4nodeSaIS0_EE5beginEv;	.scl	2;	.type	32;	.endef
__ZNKSt5dequeI4nodeSaIS0_EE5beginEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	ret	$4
	.section	.text$_ZNKSt5dequeI4nodeSaIS0_EE3endEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt5dequeI4nodeSaIS0_EE3endEv
	.def	__ZNKSt5dequeI4nodeSaIS0_EE3endEv;	.scl	2;	.type	32;	.endef
__ZNKSt5dequeI4nodeSaIS0_EE3endEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	24(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	ret	$4
	.section	.text$_ZSt22__uninitialized_copy_aISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_ES1_ET0_T_SA_S9_RSaIT1_E,"x"
	.linkonce discard
	.globl	__ZSt22__uninitialized_copy_aISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_ES1_ET0_T_SA_S9_RSaIT1_E
	.def	__ZSt22__uninitialized_copy_aISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_ES1_ET0_T_SA_S9_RSaIT1_E;	.scl	2;	.type	32;	.endef
__ZSt22__uninitialized_copy_aISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_ES1_ET0_T_SA_S9_RSaIT1_E:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	leal	-24(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt18uninitialized_copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE9constructIS1_EEvRS2_PS1_RKT_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE9constructIS1_EEvRS2_PS1_RKT_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE9constructIS1_EEvRS2_PS1_RKT_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE9constructIS1_EEvRS2_PS1_RKT_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_
	subl	$8, %esp
	nop
	leave
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_
	.def	__ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$92, %esp
	movl	%ecx, -28(%ebp)
	movl	$___gxx_personality_sj0, -56(%ebp)
	movl	$LLSDA1536, -52(%ebp)
	leal	-48(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L127, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	-28(%ebp), %eax
	movl	$1, (%esp)
	movl	$-1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE22_M_reserve_map_at_backEj
	subl	$4, %esp
	movl	-28(%ebp), %eax
	movl	36(%eax), %eax
	addl	$4, %eax
	movl	%eax, -84(%ebp)
	movl	-28(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv
	movl	-84(%ebp), %esi
	movl	%eax, (%esi)
	movl	-28(%ebp), %eax
	movl	24(%eax), %edx
	movl	-28(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_
	subl	$8, %esp
	movl	-28(%ebp), %eax
	movl	36(%eax), %eax
	leal	4(%eax), %edx
	movl	-28(%ebp), %eax
	addl	$24, %eax
	movl	%edx, (%esp)
	movl	$1, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-28(%ebp), %eax
	movl	28(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, 24(%eax)
	jmp	L130
L127:
	leal	24(%ebp), %ebp
	movl	-72(%ebp), %edx
	movl	-76(%ebp), %eax
	testl	%eax, %eax
	je	L128
	subl	$1, %eax
	testl	%eax, %eax
	je	L129
	subl	$1, %eax
	ud2
L128:
	movl	%edx, %eax
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-28(%ebp), %eax
	movl	36(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%esp)
	movl	$2, -76(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_
	subl	$4, %esp
	call	___cxa_rethrow
L129:
	movl	%edx, -84(%ebp)
	movl	$0, -76(%ebp)
	call	___cxa_end_catch
	movl	-84(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -76(%ebp)
	call	__Unwind_SjLj_Resume
L130:
	leal	-80(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1536:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1536-LLSDATTD1536
LLSDATTD1536:
	.byte	0x1
	.uleb128 LLSDACSE1536-LLSDACSB1536
LLSDACSB1536:
	.uleb128 0
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0
LLSDACSE1536:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1536:
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE16_M_push_back_auxERKS0_,"x"
	.linkonce discard
	.section	.text$_ZSteqI4nodeRS0_PS0_EbRKSt15_Deque_iteratorIT_T0_T1_ES9_,"x"
	.linkonce discard
	.globl	__ZSteqI4nodeRS0_PS0_EbRKSt15_Deque_iteratorIT_T0_T1_ES9_
	.def	__ZSteqI4nodeRS0_PS0_EbRKSt15_Deque_iteratorIT_T0_T1_ES9_;	.scl	2;	.type	32;	.endef
__ZSteqI4nodeRS0_PS0_EbRKSt15_Deque_iteratorIT_T0_T1_ES9_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	sete	%al
	popl	%ebp
	ret
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeE7destroyEPS1_
	subl	$4, %esp
	nop
	leave
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE16_M_pop_front_auxEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE16_M_pop_front_auxEv
	.def	__ZNSt5dequeI4nodeSaIS0_EE16_M_pop_front_auxEv;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE16_M_pop_front_auxEv:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%eax), %ebx
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE7destroyERS2_PS1_
	movl	-12(%ebp), %eax
	movl	12(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	20(%eax), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	12(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	nop
	movl	-4(%ebp), %ebx
	leave
	ret
	.section	.text$_ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv
	.def	__ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	ret
	.section	.text$_ZNSaI4nodeEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaI4nodeEC2Ev
	.def	__ZNSaI4nodeEC2Ev;	.scl	2;	.type	32;	.endef
__ZNSaI4nodeEC2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeEC2Ev
	nop
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev
	.def	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	$0, (%eax)
	movl	-4(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 8(%eax)
	movl	-4(%ebp), %eax
	movl	$0, 12(%eax)
	nop
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeED2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret
	.section	.text$_ZSt3maxIjERKT_S2_S2_,"x"
	.linkonce discard
	.globl	__ZSt3maxIjERKT_S2_S2_
	.def	__ZSt3maxIjERKT_S2_S2_;	.scl	2;	.type	32;	.endef
__ZSt3maxIjERKT_S2_S2_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	cmpl	%eax, %edx
	jnb	L141
	movl	12(%ebp), %eax
	jmp	L142
L141:
	movl	8(%ebp), %eax
L142:
	popl	%ebp
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	%ecx, -44(%ebp)
	movl	$___gxx_personality_sj0, -72(%ebp)
	movl	$LLSDA1552, -68(%ebp)
	leal	-64(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L146, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	leal	-25(%ebp), %eax
	movl	-44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-25(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -92(%ebp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE8allocateERS3_j
	movl	%eax, -100(%ebp)
	leal	-25(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP4nodeED1Ev
	movl	-100(%ebp), %eax
	movl	%eax, -100(%ebp)
	jmp	L148
L146:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %eax
	movl	%eax, -100(%ebp)
	leal	-25(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSaIP4nodeED1Ev
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__Unwind_SjLj_Resume
L148:
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	movl	-100(%ebp), %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$4
	.section	.gcc_except_table,"w"
LLSDA1552:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1552-LLSDACSB1552
LLSDACSB1552:
	.uleb128 0
	.uleb128 0
LLSDACSE1552:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj,"x"
	.linkonce discard
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$108, %esp
	movl	%ecx, -44(%ebp)
	movl	$___gxx_personality_sj0, -72(%ebp)
	movl	$LLSDA1553, -68(%ebp)
	leal	-64(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L154, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	movl	8(%ebp), %eax
	movl	%eax, -28(%ebp)
L151:
	movl	-28(%ebp), %eax
	cmpl	12(%ebp), %eax
	jnb	L157
	movl	-44(%ebp), %eax
	movl	$1, -92(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv
	movl	%eax, %edx
	movl	-28(%ebp), %eax
	movl	%edx, (%eax)
	addl	$4, -28(%ebp)
	jmp	L151
L154:
	leal	24(%ebp), %ebp
	movl	-88(%ebp), %edx
	movl	-92(%ebp), %eax
	testl	%eax, %eax
	je	L155
	subl	$1, %eax
	testl	%eax, %eax
	je	L156
	subl	$1, %eax
	ud2
L155:
	movl	%edx, %eax
	movl	%eax, (%esp)
	call	___cxa_begin_catch
	movl	-44(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	$2, -92(%ebp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_destroy_nodesEPPS0_S4_
	subl	$8, %esp
	call	___cxa_rethrow
L156:
	movl	%edx, -100(%ebp)
	movl	$0, -92(%ebp)
	call	___cxa_end_catch
	movl	-100(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -92(%ebp)
	call	__Unwind_SjLj_Resume
L157:
	nop
	leal	-96(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret	$8
	.section	.gcc_except_table,"w"
	.align 4
LLSDA1553:
	.byte	0xff
	.byte	0
	.uleb128 LLSDATT1553-LLSDATTD1553
LLSDATTD1553:
	.byte	0x1
	.uleb128 LLSDACSE1553-LLSDACSB1553
LLSDACSB1553:
	.uleb128 0
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0
LLSDACSE1553:
	.byte	0x1
	.byte	0
	.align 4
	.long	0
LLSDATT1553:
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_create_nodesEPPS0_S4_,"x"
	.linkonce discard
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	.def	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-12(%ebp), %eax
	movl	4(%eax), %ebx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv
	sall	$4, %eax
	leal	(%ebx,%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%eax)
	nop
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret	$4
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE18_M_deallocate_nodeEPS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE10deallocateERS2_PS1_j
	nop
	leave
	ret	$4
	.section	.text$_ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv
	.def	__ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv;	.scl	2;	.type	32;	.endef
__ZNKSt11_Deque_baseI4nodeSaIS0_EE20_M_get_map_allocatorEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %ecx
	call	__ZNKSt11_Deque_baseI4nodeSaIS0_EE19_M_get_Tp_allocatorEv
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSaIP4nodeEC1IS_EERKSaIT_E
	subl	$4, %esp
	movl	-12(%ebp), %eax
	leave
	ret	$4
	.section	.text$_ZNSaIP4nodeED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIP4nodeED1Ev
	.def	__ZNSaIP4nodeED1Ev;	.scl	2;	.type	32;	.endef
__ZNSaIP4nodeED1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP4nodeED2Ev
	nop
	leave
	ret
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE10deallocateERS3_PS2_j,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE10deallocateERS3_PS2_j
	.def	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE10deallocateERS3_PS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE10deallocateERS3_PS2_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP4nodeE10deallocateEPS2_j
	subl	$8, %esp
	nop
	leave
	ret
	.section	.text$_ZStmiI4nodeRS0_PS0_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS7_SA_,"x"
	.linkonce discard
	.globl	__ZStmiI4nodeRS0_PS0_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS7_SA_
	.def	__ZStmiI4nodeRS0_PS0_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS7_SA_;	.scl	2;	.type	32;	.endef
__ZStmiI4nodeRS0_PS0_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS7_SA_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, %ecx
	movl	12(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$2, %eax
	subl	$1, %eax
	imull	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %ecx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	addl	%edx, %eax
	leave
	ret
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1ERKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1ERKS1_
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1ERKS1_;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE11_Deque_implC1ERKS1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSaI4nodeEC2ERKS0_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	$0, (%eax)
	movl	-12(%ebp), %eax
	movl	$0, 4(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev
	movl	-12(%ebp), %eax
	addl	$24, %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1Ev
	nop
	leave
	ret	$4
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E
	.def	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EC1ERKS_IS0_RS0_PS0_E:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, (%eax)
	movl	8(%ebp), %eax
	movl	4(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	8(%ebp), %eax
	movl	8(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 8(%eax)
	movl	8(%ebp), %eax
	movl	12(%eax), %edx
	movl	-4(%ebp), %eax
	movl	%edx, 12(%eax)
	nop
	leave
	ret	$4
	.section	.text$_ZSt18uninitialized_copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_,"x"
	.linkonce discard
	.globl	__ZSt18uninitialized_copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_
	.def	__ZSt18uninitialized_copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_;	.scl	2;	.type	32;	.endef
__ZSt18uninitialized_copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movb	$1, -9(%ebp)
	leal	-28(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt15_Deque_iteratorI4nodeRKS3_PS4_ES2_IS3_RS3_PS3_EEET0_T_SC_SB_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeE9constructEPS1_RKS1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$12, %esp
	movl	%ecx, -4(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$16, (%esp)
	call	__ZnwjPv
	testl	%eax, %eax
	je	L173
	movl	12(%ebp), %edx
	movl	(%edx), %ecx
	movl	%ecx, (%eax)
	movl	4(%edx), %ecx
	movl	%ecx, 4(%eax)
	movl	8(%edx), %ecx
	movl	%ecx, 8(%eax)
	movl	12(%edx), %edx
	movl	%edx, 12(%eax)
L173:
	nop
	leave
	ret	$8
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE22_M_reserve_map_at_backEj,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE22_M_reserve_map_at_backEj
	.def	__ZNSt5dequeI4nodeSaIS0_EE22_M_reserve_map_at_backEj;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE22_M_reserve_map_at_backEj:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	leal	1(%eax), %ecx
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	36(%eax), %eax
	movl	%eax, %ebx
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %ebx
	movl	%ebx, %eax
	sarl	$2, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	cmpl	%eax, %ecx
	jbe	L176
	movl	-12(%ebp), %eax
	movl	$0, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EE17_M_reallocate_mapEjb
	subl	$8, %esp
L176:
	nop
	movl	-4(%ebp), %ebx
	leave
	ret	$4
	.section	.text$_ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv
	.def	__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv;	.scl	2;	.type	32;	.endef
__ZNSt11_Deque_baseI4nodeSaIS0_EE16_M_allocate_nodeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	movl	%eax, %edx
	movl	-12(%ebp), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE8allocateERS2_j
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeE7destroyEPS1_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeE7destroyEPS1_
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeE7destroyEPS1_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeE7destroyEPS1_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret	$4
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeEC2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE8allocateERS3_j,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE8allocateERS3_j
	.def	__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE8allocateERS3_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaIP4nodeEE8allocateERS3_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP4nodeE8allocateEjPKv
	subl	$8, %esp
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv,"x"
	.linkonce discard
	.globl	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv
	.def	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E14_S_buffer_sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	leave
	ret
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE10deallocateERS2_PS1_j,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE10deallocateERS2_PS1_j
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE10deallocateERS2_PS1_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE10deallocateERS2_PS1_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeE10deallocateEPS1_j
	subl	$8, %esp
	nop
	leave
	ret
	.section	.text$_ZNSaIP4nodeEC1IS_EERKSaIT_E,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaIP4nodeEC1IS_EERKSaIT_E
	.def	__ZNSaIP4nodeEC1IS_EERKSaIT_E;	.scl	2;	.type	32;	.endef
__ZNSaIP4nodeEC1IS_EERKSaIT_E:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorIP4nodeEC2Ev
	nop
	leave
	ret	$4
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP4nodeED2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP4nodeED2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIP4nodeED2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP4nodeED2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP4nodeE10deallocateEPS2_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP4nodeE10deallocateEPS2_j
	.def	__ZN9__gnu_cxx13new_allocatorIP4nodeE10deallocateEPS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP4nodeE10deallocateEPS2_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	ret	$8
	.section	.text$_ZNSaI4nodeEC2ERKS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSaI4nodeEC2ERKS0_
	.def	__ZNSaI4nodeEC2ERKS0_;	.scl	2;	.type	32;	.endef
__ZNSaI4nodeEC2ERKS0_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeEC2ERKS2_
	subl	$4, %esp
	nop
	leave
	ret	$4
	.section	.text$_ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt15_Deque_iteratorI4nodeRKS3_PS4_ES2_IS3_RS3_PS3_EEET0_T_SC_SB_,"x"
	.linkonce discard
	.globl	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt15_Deque_iteratorI4nodeRKS3_PS4_ES2_IS3_RS3_PS3_EEET0_T_SC_SB_
	.def	__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt15_Deque_iteratorI4nodeRKS3_PS4_ES2_IS3_RS3_PS3_EEET0_T_SC_SB_;	.scl	2;	.type	32;	.endef
__ZNSt20__uninitialized_copyILb1EE13__uninit_copyISt15_Deque_iteratorI4nodeRKS3_PS4_ES2_IS3_RS3_PS3_EEET0_T_SC_SB_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$72, %esp
	leal	-24(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt4copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt5dequeI4nodeSaIS0_EE17_M_reallocate_mapEjb,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5dequeI4nodeSaIS0_EE17_M_reallocate_mapEjb
	.def	__ZNSt5dequeI4nodeSaIS0_EE17_M_reallocate_mapEjb;	.scl	2;	.type	32;	.endef
__ZNSt5dequeI4nodeSaIS0_EE17_M_reallocate_mapEjb:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$68, %esp
	movl	%ecx, -44(%ebp)
	movl	12(%ebp), %eax
	movb	%al, -48(%ebp)
	movl	-44(%ebp), %eax
	movl	36(%eax), %eax
	movl	%eax, %edx
	movl	-44(%ebp), %eax
	movl	20(%eax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	addl	$1, %eax
	movl	%eax, -16(%ebp)
	movl	8(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%ebp)
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	movl	-20(%ebp), %edx
	addl	%edx, %edx
	cmpl	%edx, %eax
	jbe	L193
	movl	-44(%ebp), %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %eax
	movl	4(%eax), %eax
	subl	-20(%ebp), %eax
	shrl	%eax
	leal	0(,%eax,4), %ecx
	cmpb	$0, -48(%ebp)
	je	L194
	movl	8(%ebp), %eax
	sall	$2, %eax
	jmp	L195
L194:
	movl	$0, %eax
L195:
	addl	%ecx, %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	20(%eax), %eax
	cmpl	-12(%ebp), %eax
	jbe	L196
	movl	-44(%ebp), %eax
	movl	36(%eax), %eax
	leal	4(%eax), %ecx
	movl	-44(%ebp), %eax
	movl	20(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4copyIPP4nodeS2_ET0_T_S4_S3_
	jmp	L198
L196:
	movl	-16(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	-12(%ebp), %eax
	leal	(%edx,%eax), %ecx
	movl	-44(%ebp), %eax
	movl	36(%eax), %eax
	leal	4(%eax), %edx
	movl	-44(%ebp), %eax
	movl	20(%eax), %eax
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13copy_backwardIPP4nodeS2_ET0_T_S4_S3_
	jmp	L198
L193:
	movl	-44(%ebp), %eax
	movl	4(%eax), %ebx
	movl	-44(%ebp), %eax
	addl	$4, %eax
	leal	8(%ebp), %ecx
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt3maxIjERKT_S2_S2_
	movl	(%eax), %eax
	addl	%ebx, %eax
	addl	$2, %eax
	movl	%eax, -24(%ebp)
	movl	-44(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE15_M_allocate_mapEj
	subl	$4, %esp
	movl	%eax, -28(%ebp)
	movl	-24(%ebp), %eax
	subl	-20(%ebp), %eax
	shrl	%eax
	leal	0(,%eax,4), %edx
	cmpb	$0, -48(%ebp)
	je	L199
	movl	8(%ebp), %eax
	sall	$2, %eax
	jmp	L200
L199:
	movl	$0, %eax
L200:
	addl	%eax, %edx
	movl	-28(%ebp), %eax
	addl	%edx, %eax
	movl	%eax, -12(%ebp)
	movl	-44(%ebp), %eax
	movl	36(%eax), %eax
	leal	4(%eax), %ecx
	movl	-44(%ebp), %eax
	movl	20(%eax), %eax
	movl	-12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%ecx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt4copyIPP4nodeS2_ET0_T_S4_S3_
	movl	-44(%ebp), %eax
	movl	4(%eax), %ecx
	movl	-44(%ebp), %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %eax
	movl	%ecx, 4(%esp)
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt11_Deque_baseI4nodeSaIS0_EE17_M_deallocate_mapEPPS0_j
	subl	$8, %esp
	movl	-44(%ebp), %eax
	movl	-28(%ebp), %edx
	movl	%edx, (%eax)
	movl	-44(%ebp), %eax
	movl	-24(%ebp), %edx
	movl	%edx, 4(%eax)
L198:
	movl	-44(%ebp), %eax
	leal	8(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-16(%ebp), %eax
	addl	$1073741823, %eax
	leal	0(,%eax,4), %edx
	movl	-12(%ebp), %eax
	addl	%eax, %edx
	movl	-44(%ebp), %eax
	addl	$24, %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	nop
	movl	-4(%ebp), %ebx
	leave
	ret	$8
	.section	.text$_ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE8allocateERS2_j,"x"
	.linkonce discard
	.globl	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE8allocateERS2_j
	.def	__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE8allocateERS2_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx14__alloc_traitsISaI4nodeEE8allocateERS2_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN9__gnu_cxx13new_allocatorI4nodeE8allocateEjPKv
	subl	$8, %esp
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP4nodeE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP4nodeE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorIP4nodeE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP4nodeE8allocateEjPKv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorIP4nodeE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L204
	call	__ZSt17__throw_bad_allocv
L204:
	movl	8(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	ret	$8
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeE10deallocateEPS1_j,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeE10deallocateEPS1_j
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeE10deallocateEPS1_j;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeE10deallocateEPS1_j:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZdlPv
	nop
	leave
	ret	$8
	.section	.text$_ZN9__gnu_cxx13new_allocatorIP4nodeEC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorIP4nodeEC2Ev
	.def	__ZN9__gnu_cxx13new_allocatorIP4nodeEC2Ev;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorIP4nodeEC2Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeEC2ERKS2_,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeEC2ERKS2_
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeEC2ERKS2_;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeEC2ERKS2_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	nop
	leave
	ret	$4
	.section	.text$_ZSt4copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_,"x"
	.linkonce discard
	.globl	__ZSt4copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_
	.def	__ZSt4copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_;	.scl	2;	.type	32;	.endef
__ZSt4copyISt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET0_T_SA_S9_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$104, %esp
	leal	-56(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	leal	-40(%ebp), %eax
	movl	28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_
	leal	-24(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_
	movl	8(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	-40(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	-36(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt14__copy_move_a2ILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt4copyIPP4nodeS2_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt4copyIPP4nodeS2_ET0_T_S4_S3_
	.def	__ZSt4copyIPP4nodeS2_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt4copyIPP4nodeS2_ET0_T_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt14__copy_move_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZSt13copy_backwardIPP4nodeS2_ET0_T_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt13copy_backwardIPP4nodeS2_ET0_T_S4_S3_
	.def	__ZSt13copy_backwardIPP4nodeS2_ET0_T_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt13copy_backwardIPP4nodeS2_ET0_T_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$20, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_
	movl	%eax, %edx
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edx, (%esp)
	call	__ZSt23__copy_move_backward_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_
	addl	$20, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section	.text$_ZN9__gnu_cxx13new_allocatorI4nodeE8allocateEjPKv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN9__gnu_cxx13new_allocatorI4nodeE8allocateEjPKv
	.def	__ZN9__gnu_cxx13new_allocatorI4nodeE8allocateEjPKv;	.scl	2;	.type	32;	.endef
__ZN9__gnu_cxx13new_allocatorI4nodeE8allocateEjPKv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNK9__gnu_cxx13new_allocatorI4nodeE8max_sizeEv
	cmpl	8(%ebp), %eax
	setb	%al
	testb	%al, %al
	je	L216
	call	__ZSt17__throw_bad_allocv
L216:
	movl	8(%ebp), %eax
	sall	$4, %eax
	movl	%eax, (%esp)
	call	__Znwj
	leave
	ret	$8
	.section	.text$_ZNK9__gnu_cxx13new_allocatorIP4nodeE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorIP4nodeE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorIP4nodeE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorIP4nodeE8max_sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$1073741823, %eax
	leave
	ret
	.section	.text$_ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_
	.def	__ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Miter_baseIT_E13iterator_typeES7_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt14__copy_move_a2ILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_
	.def	__ZSt14__copy_move_a2ILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$120, %esp
	leal	-56(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	leal	-72(%ebp), %eax
	leal	-56(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRS1_PS1_EENSt11_Niter_baseIT_E13iterator_typeES6_
	leal	-40(%ebp), %eax
	movl	28(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_
	leal	-24(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_
	movl	8(%ebp), %eax
	leal	-72(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	-40(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	-36(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-32(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	-20(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_,"x"
	.linkonce discard
	.globl	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_
	.def	__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_;	.scl	2;	.type	32;	.endef
__ZSt12__miter_baseIPP4nodeENSt11_Miter_baseIT_E13iterator_typeES4_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_
	leave
	ret
	.section	.text$_ZSt14__copy_move_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt14__copy_move_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_
	.def	__ZSt14__copy_move_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt14__copy_move_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt13__copy_move_aILb0EPP4nodeS2_ET1_T0_S4_S3_
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section	.text$_ZSt23__copy_move_backward_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt23__copy_move_backward_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_
	.def	__ZSt23__copy_move_backward_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt23__copy_move_backward_a2ILb0EPP4nodeS2_ET1_T0_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	subl	$16, %esp
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %esi
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%eax, %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZSt22__copy_move_backward_aILb0EPP4nodeS2_ET1_T0_S4_S3_
	addl	$16, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.section	.text$_ZNK9__gnu_cxx13new_allocatorI4nodeE8max_sizeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNK9__gnu_cxx13new_allocatorI4nodeE8max_sizeEv
	.def	__ZNK9__gnu_cxx13new_allocatorI4nodeE8max_sizeEv;	.scl	2;	.type	32;	.endef
__ZNK9__gnu_cxx13new_allocatorI4nodeE8max_sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	$268435455, %eax
	leave
	ret
	.section	.text$_ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_
	.def	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%eax)
	movl	16(%ebp), %edx
	movl	%edx, 4(%eax)
	movl	20(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	24(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_
	.def	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_EENSt11_Niter_baseIT_E13iterator_typeES7_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$20, %esp
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRKS1_PS2_ELb0EE7_S_baseES5_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt12__niter_baseISt15_Deque_iteratorI4nodeRS1_PS1_EENSt11_Niter_baseIT_E13iterator_typeES6_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRS1_PS1_EENSt11_Niter_baseIT_E13iterator_typeES6_
	.def	__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRS1_PS1_EENSt11_Niter_baseIT_E13iterator_typeES6_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseISt15_Deque_iteratorI4nodeRS1_PS1_EENSt11_Niter_baseIT_E13iterator_typeES6_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	leal	-24(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-24(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRS1_PS1_ELb0EE7_S_baseES4_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZSt13__copy_move_aILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_
	.def	__ZSt13__copy_move_aILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb0ESt15_Deque_iteratorI4nodeRKS1_PS2_ES0_IS1_RS1_PS1_EET1_T0_SA_S9_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$88, %esp
	movb	$0, -9(%ebp)
	leal	-28(%ebp), %eax
	movl	44(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leal	-28(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	36(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 32(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mISt15_Deque_iteratorI4nodeRKS4_PS5_ES3_IS4_RS4_PS4_EEET0_T_SD_SC_
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_
	.def	__ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section	.text$_ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_,"x"
	.linkonce discard
	.globl	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_
	.def	__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_;	.scl	2;	.type	32;	.endef
__ZSt12__niter_baseIPP4nodeENSt11_Niter_baseIT_E13iterator_typeES4_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt10_Iter_baseIPP4nodeLb0EE7_S_baseES2_
	leave
	ret
	.section	.text$_ZSt13__copy_move_aILb0EPP4nodeS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt13__copy_move_aILb0EPP4nodeS2_ET1_T0_S4_S3_
	.def	__ZSt13__copy_move_aILb0EPP4nodeS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt13__copy_move_aILb0EPP4nodeS2_ET1_T0_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP4nodeEEPT_PKS5_S8_S6_
	leave
	ret
	.section	.text$_ZSt22__copy_move_backward_aILb0EPP4nodeS2_ET1_T0_S4_S3_,"x"
	.linkonce discard
	.globl	__ZSt22__copy_move_backward_aILb0EPP4nodeS2_ET1_T0_S4_S3_
	.def	__ZSt22__copy_move_backward_aILb0EPP4nodeS2_ET1_T0_S4_S3_;	.scl	2;	.type	32;	.endef
__ZSt22__copy_move_backward_aILb0EPP4nodeS2_ET1_T0_S4_S3_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movb	$1, -9(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIP4nodeEEPT_PKS5_S8_S6_
	leave
	ret
	.section	.text$_ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRS1_PS1_ELb0EE7_S_baseES4_,"x"
	.linkonce discard
	.globl	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRS1_PS1_ELb0EE7_S_baseES4_
	.def	__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRS1_PS1_ELb0EE7_S_baseES4_;	.scl	2;	.type	32;	.endef
__ZNSt10_Iter_baseISt15_Deque_iteratorI4nodeRS1_PS1_ELb0EE7_S_baseES4_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mISt15_Deque_iteratorI4nodeRKS4_PS5_ES3_IS4_RS4_PS4_EEET0_T_SD_SC_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mISt15_Deque_iteratorI4nodeRKS4_PS5_ES3_IS4_RS4_PS4_EEET0_T_SD_SC_
	.def	__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mISt15_Deque_iteratorI4nodeRKS4_PS5_ES3_IS4_RS4_PS4_EEET0_T_SD_SC_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb0ELb0ESt26random_access_iterator_tagE8__copy_mISt15_Deque_iteratorI4nodeRKS4_PS5_ES3_IS4_RS4_PS4_EEET0_T_SD_SC_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	leal	12(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	28(%ebp), %eax
	movl	%eax, (%esp)
	call	__ZStmiI4nodeRKS0_PS1_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS8_SB_
	movl	%eax, -12(%ebp)
L252:
	cmpl	$0, -12(%ebp)
	jle	L251
	movl	44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt15_Deque_iteratorI4nodeRS0_PS0_EdeEv
	movl	%eax, %ebx
	leal	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNKSt15_Deque_iteratorI4nodeRKS0_PS1_EdeEv
	movl	(%eax), %edx
	movl	%edx, (%ebx)
	movl	4(%eax), %edx
	movl	%edx, 4(%ebx)
	movl	8(%eax), %edx
	movl	%edx, 8(%ebx)
	movl	12(%eax), %eax
	movl	%eax, 12(%ebx)
	leal	12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EppEv
	movl	44(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EppEv
	subl	$1, -12(%ebp)
	jmp	L252
L251:
	movl	44(%ebp), %eax
	movl	%eax, (%esp)
	movl	8(%ebp), %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EC1ERKS3_
	subl	$4, %esp
	movl	8(%ebp), %eax
	movl	-4(%ebp), %ebx
	leave
	ret
	.section	.text$_ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP4nodeEEPT_PKS5_S8_S6_,"x"
	.linkonce discard
	.globl	__ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP4nodeEEPT_PKS5_S8_S6_
	.def	__ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP4nodeEEPT_PKS5_S8_S6_;	.scl	2;	.type	32;	.endef
__ZNSt11__copy_moveILb0ELb1ESt26random_access_iterator_tagE8__copy_mIP4nodeEEPT_PKS5_S8_S6_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L255
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	16(%ebp), %eax
	movl	%eax, (%esp)
	call	_memmove
L255:
	movl	-12(%ebp), %eax
	leal	0(,%eax,4), %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	ret
	.section	.text$_ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIP4nodeEEPT_PKS5_S8_S6_,"x"
	.linkonce discard
	.globl	__ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIP4nodeEEPT_PKS5_S8_S6_
	.def	__ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIP4nodeEEPT_PKS5_S8_S6_;	.scl	2;	.type	32;	.endef
__ZNSt20__copy_move_backwardILb0ELb1ESt26random_access_iterator_tagE13__copy_move_bIP4nodeEEPT_PKS5_S8_S6_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	sarl	$2, %eax
	movl	%eax, -12(%ebp)
	cmpl	$0, -12(%ebp)
	je	L258
	movl	-12(%ebp), %eax
	sall	$2, %eax
	movl	-12(%ebp), %edx
	sall	$2, %edx
	movl	%edx, %ecx
	negl	%ecx
	movl	16(%ebp), %edx
	addl	%ecx, %edx
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	_memmove
L258:
	movl	-12(%ebp), %eax
	sall	$2, %eax
	negl	%eax
	movl	%eax, %edx
	movl	16(%ebp), %eax
	addl	%edx, %eax
	leave
	ret
	.section	.text$_ZStmiI4nodeRKS0_PS1_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS8_SB_,"x"
	.linkonce discard
	.globl	__ZStmiI4nodeRKS0_PS1_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS8_SB_
	.def	__ZStmiI4nodeRKS0_PS1_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS8_SB_;	.scl	2;	.type	32;	.endef
__ZStmiI4nodeRKS0_PS1_ENSt15_Deque_iteratorIT_T0_T1_E15difference_typeERKS8_SB_:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv
	movl	%eax, %edx
	movl	8(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, %ecx
	movl	12(%ebp), %eax
	movl	12(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$2, %eax
	subl	$1, %eax
	imull	%eax, %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, %ecx
	movl	8(%ebp), %eax
	movl	4(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	addl	%eax, %edx
	movl	12(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, %ecx
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	sarl	$4, %eax
	addl	%edx, %eax
	leave
	ret
	.section	.text$_ZNKSt15_Deque_iteratorI4nodeRKS0_PS1_EdeEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNKSt15_Deque_iteratorI4nodeRKS0_PS1_EdeEv
	.def	__ZNKSt15_Deque_iteratorI4nodeRKS0_PS1_EdeEv;	.scl	2;	.type	32;	.endef
__ZNKSt15_Deque_iteratorI4nodeRKS0_PS1_EdeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	%ecx, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	(%eax), %eax
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EppEv
	.def	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EppEv;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_EppEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jne	L265
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E11_M_set_nodeEPPS0_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
L265:
	movl	-12(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRS0_PS0_EppEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EppEv
	.def	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EppEv;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRS0_PS0_EppEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	leal	16(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	(%eax), %edx
	movl	-12(%ebp), %eax
	movl	8(%eax), %eax
	cmpl	%eax, %edx
	jne	L268
	movl	-12(%ebp), %eax
	movl	12(%eax), %eax
	leal	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZNSt15_Deque_iteratorI4nodeRS0_PS0_E11_M_set_nodeEPS2_
	subl	$4, %esp
	movl	-12(%ebp), %eax
	movl	4(%eax), %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
L268:
	movl	-12(%ebp), %eax
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv,"x"
	.linkonce discard
	.globl	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv
	.def	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$4, %esp
	movl	$16, (%esp)
	call	__ZSt16__deque_buf_sizej
	leave
	ret
	.section	.text$_ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E11_M_set_nodeEPPS0_,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E11_M_set_nodeEPPS0_
	.def	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E11_M_set_nodeEPPS0_;	.scl	2;	.type	32;	.endef
__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E11_M_set_nodeEPPS0_:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$4, %esp
	movl	%ecx, -8(%ebp)
	movl	-8(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	8(%ebp), %eax
	movl	(%eax), %edx
	movl	-8(%ebp), %eax
	movl	%edx, 4(%eax)
	movl	-8(%ebp), %eax
	movl	4(%eax), %ebx
	call	__ZNSt15_Deque_iteratorI4nodeRKS0_PS1_E14_S_buffer_sizeEv
	sall	$4, %eax
	leal	(%ebx,%eax), %edx
	movl	-8(%ebp), %eax
	movl	%edx, 8(%eax)
	nop
	addl	$4, %esp
	popl	%ebx
	popl	%ebp
	ret	$4
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.section	.text$_ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEED1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEED1Ev
	.def	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEED1Ev;	.scl	2;	.type	32;	.endef
__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEED1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EED1Ev
	nop
	leave
	ret
	.text
	.def	___tcf_1;	.scl	3;	.type	32;	.endef
___tcf_1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEED1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$140, %esp
	movl	$___gxx_personality_sj0, -100(%ebp)
	movl	$LLSDA1639, -96(%ebp)
	leal	-92(%ebp), %eax
	leal	-24(%ebp), %ebx
	movl	%ebx, (%eax)
	movl	$L279, %edx
	movl	%edx, 4(%eax)
	movl	%esp, 8(%eax)
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Register
	cmpl	$1, 8(%ebp)
	jne	L276
	cmpl	$65535, 12(%ebp)
	jne	L276
	movl	$-1, -120(%ebp)
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	leal	-64(%ebp), %eax
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EEC1Ev
	leal	-64(%ebp), %eax
	movl	%eax, (%esp)
	movl	$1, -120(%ebp)
	movl	$_q, %ecx
	call	__ZNSt5queueI4nodeSt5dequeIS0_SaIS0_EEEC1ERKS3_
	subl	$4, %esp
	leal	-64(%ebp), %eax
	movl	$-1, -120(%ebp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EED1Ev
	movl	$___tcf_1, (%esp)
	call	_atexit
	jmp	L276
L279:
	leal	24(%ebp), %ebp
	movl	-116(%ebp), %eax
	movl	%eax, -128(%ebp)
	leal	-64(%ebp), %eax
	movl	$0, -120(%ebp)
	movl	%eax, %ecx
	call	__ZNSt5dequeI4nodeSaIS0_EED1Ev
	movl	-128(%ebp), %eax
	movl	%eax, (%esp)
	movl	$-1, -120(%ebp)
	call	__Unwind_SjLj_Resume
L276:
	leal	-124(%ebp), %eax
	movl	%eax, (%esp)
	call	__Unwind_SjLj_Unregister
	leal	-12(%ebp), %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.section	.gcc_except_table,"w"
LLSDA1639:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 LLSDACSE1639-LLSDACSB1639
LLSDACSB1639:
	.uleb128 0
	.uleb128 0
LLSDACSE1639:
	.text
	.def	__GLOBAL__sub_I_visit;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_visit:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_visit
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	__ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt9basic_iosIcSt11char_traitsIcEEcvPvEv;	.scl	2;	.type	32;	.endef
	.def	_memset;	.scl	2;	.type	32;	.endef
	.def	__ZStrsIcSt11char_traitsIcEERSt13basic_istreamIT_T0_ES6_RS3_;	.scl	2;	.type	32;	.endef
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	__Unwind_SjLj_Resume;	.scl	2;	.type	32;	.endef
	.def	___cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	___cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	___cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	__ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	__Znwj;	.scl	2;	.type	32;	.endef
	.def	_memmove;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
