#include <iostream>
#include <array>
//#include <string>
//#include <vector>
//#include <sstream>
//#include <fstream>
// #include "Random.h"

#include "XorShift256.h"

//g++ -std=c++17 Random.cpp decay0.cpp Run_Decay0.cpp -o Run_Decay0 -lgsl


//g++ -std=c++17 Run_me.cpp -o Run_me 
#include <ctime>



#include <stdint.h>

// static uint64_t seed_; /* The state can be seeded with any value. */

// uint64_t SplitMix64_next() {
// 	uint64_t z = (seed_ += 0x9e3779b97f4a7c15);
// 	z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
// 	z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
// 	return z ^ (z >> 31);
// }


// template <size_t N>
// inline constexpr std::uint64_t [N] SplitMix64_seeder_()
// {

//     std::uint64_t seeds[N] = {0};

//     for (unsigned int idx = 0; idx < N; ++idx)
//     {
//         seeds[idx] = SplitMix64_next();
//     }

//     return seeds;
// }

// std::uint64_t [4] SplitMix64_seeds_ = SplitMix64_seeder_<4>();




int main () 
{
    clock_t time_req;
    time_req = clock();
    double time;
    // changing the seed for the random numbergenerator 
    // constexpr std::uint64_t Seed = 777;
    // Random_Set_Seed(Seed);

    seed_ = 777;
    static uint64_t s[4]={23478234234,2342342345,234234121323,2234453453};


    for (int i=0; i<4 ; i++)
    {
        std::cout << s[i] << std::endl;
    }


    // std::array<std::uint64_t, 4> seeds_ = seeder_<4>();
    // for (int i=0; i<SplitMix64_seeds_.size() ; i++)
    // {
    //     std::cout << SplitMix64_seeds_[i] << std::endl;
    // }


    time_req = clock();
    for(int i=0;i<100000000;++i){next();}
    time_req = clock() - time_req;
    time = (float)time_req/CLOCKS_PER_SEC;
    std::cout<< "100 000 000 random numbers (RandomUniform) took "<<time<<" Seconds"<<std::endl;
    std::cout<< "Per loop is  "<<(time/100000000)*1e9<<" nano seconds"<<std::endl;

    for (int i=0; i<4 ; i++)
    {
        std::cout << s << std::endl;
    }

    // time_req = clock();
    // for(int i=0;i<100000000;++i){SplitMix64_next();}
    // time_req = clock() - time_req;
    // time = (float)time_req/CLOCKS_PER_SEC;
    // std::cout<< "100 000 000 random numbers (RandomUniform) took "<<time<<" Seconds"<<std::endl;
    // std::cout<< "Per loop is  "<<(time/100000000)*1e9<<" nano seconds"<<std::endl;


    // time_req = clock();
    // for(int i=0;i<25000000;++i){ seeder_<4>(); }
    // time_req = clock() - time_req;
    // time = (float)time_req/CLOCKS_PER_SEC;
    // std::cout<< "100 000 000 random numbers (RandomUniform) took "<<time<<" Seconds"<<std::endl;
    // std::cout<< "Per loop is  "<<(time/25000000)*1e9<<" nano seconds"<<std::endl;



    return 0;
}

