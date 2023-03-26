#include <TinyEngine/TinyEngine>
#include"yaml.hpp"

int main( int argc, char* args[] ) {

	// Basic Key-Value Yaml Node:
	// 	We need the template parameter,
	//	so that we can deduce the parser.

/*
	int t = yaml::val<int>(10);
	std::cout<<t<<std::endl;

	// Nested Struct-Type Yaml Node:

	struct B: yaml::obj {
		int t 		= B::_val<"t">(3);
	} _B, _C;
	std::cout<<_B;
	std::cout<<_C;

	//

	struct A: yaml::obj {
		float b 	= A::_val<"b">(1.5);
		B bc 			= A::_obj<"bc">(B{});
	} _A, _D;
	std::cout<<_A;
	std::cout<<_D;
*/

	/*
		note: this implies that there is a value type with key other

		I now need to make a function which generates the corresponding type,
		or rather assigns the corresponding type, casts and stores in the tuple
		appropriately using the correct parameter.
	*/

	struct B: yaml::new_obj<>{};

	struct T:
	yaml::new_obj <
		yaml::val_key<"other">,
		yaml::val_key<"other2">,
		yaml::obj_key<"test">
	>{
		int t = T::val<"other2">(10);
		B b = T::obj<"test">(B{});
	} T;

	std::cout<<T.t<<std::endl;

/*	int t = T::val<"other">(1);
		int b = T::obj<"test">();
	} T;

/*
	// Full Compile Time Resolution

	struct D: yaml::obj<"struct D"> {
		size_t n = D::val<"n">(1);
		char c = D::val<"c">('b');
	//	C c0 = yaml::obj<"C0">{};
};

	D d0;
	D d1;

//	std::cout<<"SUBSIZE "<<D.sub.size()<<std::endl;

	// Other stuff


*/

	//

	//yaml::key<"A"> midkey_a;
	//yaml::key<"B"> midkey_b;
	//yaml::key<"C"> midkey_c;
	//yaml::key<"D"> midkey_d;

	return 0;

}
