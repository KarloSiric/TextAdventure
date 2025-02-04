/*
* @Author: karlosiric
* @Date:   2025-02-04 20:08:48
* @Last Modified by:   karlosiric
* @Last Modified time: 2025-02-04 20:38:25
*/

/*
 * this here will be the parseAndExecute function and it is in another file, because it will be changing from chapter to chapter
 * And it might grow and so forth so it is better to have it in another file just to keep things clean and neat.
 */


#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool parseAndExecute(const char *input) // this is a function that takes as a param a string and returns a boolean
{
    // we will use something called strtok function from string.h that is used to split a string into tokens
    // strtok is used to split a string into tokens
    // First token is the verb going to be used
    char *verb = strtok(input, " \n"); // this will split the string into tokens, the first token is the verb
    char *noun = strtok(NULL, " \n"); // the second token is the noun, NULL is used here to continue from the last call of strtok
    
    // we will use the strcmp function from string.h to compare the verb and noun

}