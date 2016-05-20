#pragma once

__int8* create_prime_list(unsigned long long upper_bound);
void destroy_prime_list(__int8* prime_list);

int is_prime(__int8* prime_list, unsigned long long n);