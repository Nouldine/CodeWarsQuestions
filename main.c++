
#include "DirectionReduction.c++"
#include "StringMix.c++"

int main() {

	
	std::cout <<"***************** Direction Reduction *******************" << std::endl;
        std::cout << std::endl;
	DirectionReduction D;        
	std::vector<std::string> vec{"NORTH", "SOUTH", "SOUTH", "EAST", "EAST", "WEST", "NORTH", "WEST"};

        std::vector<std::string> result_vec = D.dirReduction( vec );

        std::cout <<"[";
        for( auto content : result_vec )
                std::cout << content <<" ";
        std::cout << "]" << std::endl;
	
	std::cout << std::endl;


	std::cout <<"*********************** String Mix ********************" << std::endl; 
	std::cout << std::endl;
	StringMix M;
	
	std::string str_1 = "my&friend&Paul has heavy hats! &";
        std::string str_2 = "my friend John has many many friends &";
        std::string s1 = "mmmmm m nnnnn y&friend&Paul has heavy hats! &";
        std::string s2 = "my frie n d Joh n has ma n y ma n y frie n ds n&";
	
	std::string result = M.string_mix( str_1 , str_2 ); 

	std::cout <<"Result: " << result << std::endl;

        return 0;
}

