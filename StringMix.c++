
#include <string>
#include <iostream> 
#include <vector> 
#include <map>
#include <algorithm>

class StringMix 
{

	public: 
		std::string string_mix( const std::string & my_str_1, const std::string my_str_2 )
		{ 

			std::map< char, int > map_str_1; 
			std::map< char, int > map_str_2;
			std::string my_string = ""; 
			std::vector< std::string > string_vec; 
			std::string alphabet = "abcdefghijklmnopqrstuvwxyz";			
			// Count each lowercase characters from
			// my_str_1 such that they could be used
			// in future process
			for( int it = 0; it < my_str_1.length(); ++it ) {
				
				// Check if the letter is lowercase
				// and if it is part of the alphabet 
				if( islower( my_str_1[ it ]  ) && isalpha( my_str_1[ it ] ) )
					++map_str_1[ my_str_1[ it ] ];

			} // end for
			
		 	// Count each lower case characters from
			// my_str_2 such that they could be used
			// in future processes
			for( int it = 0; it < my_str_2.length(); ++it ) { 
			
				// Check if the letter is lowercase
				// and most importantly, it is part of
				// the alphabet
				if( islower( my_str_2[  it  ] ) && isalpha( my_str_2[ it  ] ))
					++map_str_2[ my_str_2[ it ] ];
			}
		
		 // end for

		// std::cout <<"Test_1 " << std::endl; 
		
		// Get each character from the respective associative
		// containers 
		for( auto it = 0; it < alphabet.length(); ++it ) {

			auto count_1 = map_str_1.find( alphabet[ it ] ); 
			auto count_2 = map_str_2.find( alphabet[ it ] );

			// If the character is not in 
			// the map assign to its value 
			if( count_1 == map_str_1.end() ) 
				count_1->second = 0; 

			// If the character is not in the map
			// assign 0 to its value 
			if( count_2 == map_str_2.end() )
				count_2->second = 0;

			// If the substring in my_str_1 has the maximum 
			// length then proceed
			if( count_2->second < count_1->second) {
			
				// Make sure that the length of
				// the substring is strictly greater than 1
				if(  count_1->second > 1 )
					string_vec.push_back("1:" + std::string( count_1->second, count_1->first ) + "/");
			} 
	
			// The maximum substring length is in my_str_2
			else if(  count_1->second < count_2->second ) { 
				
				// Make sure that the length of
				// the substring is strictly greater than 1
				if( count_2->second > 1 )
					string_vec.push_back("2:" + std::string( count_2->second, count_2->first ) + "/" );
			}

			else // Otherwise they have the same length
			{
				if( count_2->second > 1 )
					string_vec.push_back("=:" + std::string( count_1->second, count_1->first ) + "/" );
			}

		} // end for


		// std::cout <<"Test_2: " << std::endl; 
		// Sort the string in decreasing order of their length
		// and when they have the same length, they need to be be sorted in ascending
		// lexicographic order
		std::sort( string_vec.begin(), string_vec.end(), []( const std::string & my_string_1, const std::string & my_string_2 ) -> bool { 

				return ( my_string_1.length() == my_string_2.length() ) ? my_string_1 < my_string_2 : my_string_1.length() > my_string_2.length();
						
			}
		); 

		// append in the  strings
		// in the right order
		for( auto  & content : string_vec )
			my_string += content;
		
		my_string.pop_back();

		
		return my_string;	
	
	} // end function

};
