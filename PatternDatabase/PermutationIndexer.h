#ifndef RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H
#define RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H
#include<bits/stdc++.h>
#include"math.h"
using namespace std;

template<size_t N,size_t K=N>
class PermutationIndexer{

    // Precomputed Table containing the number of ones in binary 
    //representation of each number. Largest N bit number is
    //2^N-1=(1<<N)-1;
    array<uint32_t,(1<<N)-1>onesCountLookup;

    //Precomputed Table of factorials 
    //or "picks" if N!=k
    //They are in reverse order

    array<uint32_t,K>factorials;
    public:
    //Populate factorials and ones Count table
    PermutationIndexer(){
        for(uint32_t i=0;i<(1<<N)-1;i++){
            bitset<N>bits(i);
            this->onesCountLookup=bits.count();
        }
        for(uint32_t i=0;i<K;i++){
            this->factorials[i]=pick(N-i-1,K-1-i);
        }
    }

    //Calculate the lexographic rank(the index) of permutation in O(n) complexity

    uint32_t rank(const array<uint32_t,K>&perm)const{

        //This will hold the lehmer code (int factorial number system).
        array<uint32_t,K>lehmer;

        //set if seen digits in permutation
        bitset<int>seen;

        //the first digit of lehmer code is the forst digit of permutation
        lehmer[0]=perm[0];

        //mark the digits as seen(bitset uses left to right indexing)
        seen[N-1-perm[0]]=1;

        for(uint32_t i=1;i<K;i++){
            seen[N-1-perm[i]]=1;

            //The number of seen digits to the left of this digit is count of ones left of this digit
            uint32_t numOnes=this->onesCountLookup[seen.to_ullong()>>(N-perm[i])];

            lehmer[i]=perm[i]-numOnes;
        }
        //convert the lehmer  code to base 10
        uint32_t index=0;
        for(uint32_t i=0;i<K;i++){
            index+=lehmer[i]*this->factorials[i];
        }
        return index;
    }


};
#endif //RUBIKS_CUBE_SOLVER_PERMUTATIONINDEXER_H