
#include <iostream> 
#include <string> 
#include <vector> 
#include <unordered_set> 
#include <map>


class DirectionReduction {


	public: 

		 std::map< std::string, std::string > my_map{
                                { "SOUTH", "NORTH" },
                                { "NORTH", "SOUTH" },
                                { "EAST", "WEST"  },
                                { "WEST", "EAST" },
                        };

		std::vector<std::string> dirReduction( std::vector<std::string>  my_vec ) { 
	
			std::vector<std::string> result_vec;
			int result_vec_size = 0;
	
			// Iterate through the container
			// to apply the direction constraints
			for( int i  = 0; i < my_vec.size(); ++i ) { 
		
				result_vec_size = result_vec.size();
				
				// This condition is important becauase ti checks the back of 
				// the result vector, if the direction in the back of result 
				// vector is an opposite direction of the next direction in				      
				// my_vec, which may be pushed in the result vector, pop
				// the back of the result vector
				if( result_vec_size > 0 && my_map.find( result_vec.back())->second.compare(my_vec[ i ] ) == 0 ) 
		 	
					result_vec.pop_back(); 

				else // Otherwise, push the correct direction
					result_vec.push_back( my_vec[ i ] );
			} // end for
  		 	
			return result_vec;
		
		}

};

