#pragma once
//https://github.com/llvm-mirror/compiler-rt/blob/master/lib/sanitizer_common/sanitizer_syscall_linux_x86_64.inc

namespace fast_io
{

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call()
{
	return_value_type ret;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1)
{
	return_value_type ret;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}

template<std::size_t syscall_number>
[[noreturn]] inline void system_call_no_return(auto p1)
{
	std::size_t ret;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1)
	: "rcx", "r11", "memory", "cc"
	);
}

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1, auto p2)
{
	return_value_type ret;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1), "S"(p2)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1, auto p2, auto p3)
{
	return_value_type ret;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1), "S"(p2), "d"(p3)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1, auto p2, auto p3, auto p4)
{
	return_value_type ret;
	register auto r10 __asm__("r10") = p4;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1), "S"(p2), "d"(p3), "r"(r10)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}

template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1, auto p2, auto p3, auto p4,auto p5)
{
	return_value_type ret;
	register auto r10 __asm__("r10") = p4;
	register auto r8 __asm__("r8") = p5;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1), "S"(p2), "d"(p3), "r"(r10), "r"(r8)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}
template<std::size_t syscall_number,std::signed_integral return_value_type>
requires (1<sizeof(return_value_type))
inline auto system_call(auto p1, auto p2, auto p3, auto p4,auto p5,auto p6)
{
	return_value_type ret;
	register auto r10 __asm__("r10") = p4;
	register auto r8 __asm__("r8") = p5;
	register auto r9 __asm__("r9") = p6;
	__asm__ __volatile__
	(
	"syscall"
	: "=a" (ret)
	//EDI      RSI       RDX
	: "0"(syscall_number), "D"(p1), "S"(p2), "d"(p3), "r"(r10),"r"(r8),"r"(r9)
	: "rcx", "r11", "memory", "cc"
	);
	return ret;
}
}