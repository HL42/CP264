/**
 * -------------------------------------
 * @file  powersum.c
 * file description
 * -------------------------------------
 * @author HunterLin, 169061939, linx1939@mylaurier
 *
 * @version 2025-01-15
 *
 * -------------------------------------
 */

/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n){
    int max = 2147483647;
    int min = -2147483648;
    if(n == 0 || b == 0){
        return 0;
    }

    int b_initial = 1;
    for(int i = 0; i < n; i++){
        if(b_initial > (max / b)){
            return 1;
        } else if(b_initial < (min / b)){
            return 1;
        }
        b_initial *= b;
    }

    return 0;
}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n){

    int result = 1;

    if(power_overflow(b, n)){
        return 0;
    }
    for(int i = 0; i < n; i++){
        result = b * result;
    }

    return result;


}


/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n){
    if(power_overflow(b, n)){
        return 0;
    }

    int sum = 0;
    for(int i = 0; i <= n; i++){
        sum += mypower(b, i);
    }

    return sum;
    
}
