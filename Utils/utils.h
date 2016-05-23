#pragma once
#include <stdint.h>

uint8_t* create_prime_list(uint64_t upper_bound);
void destroy_prime_list(uint8_t* prime_list);
uint8_t is_prime(uint8_t* prime_list, uint64_t n);

uint64_t* factors(uint64_t n);
uint64_t* divisors(uint64_t n);