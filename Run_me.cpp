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
// #include <inttypes.h>


#include <stdint.h>
#include <cstring>


class Rando_Bandieto
{
private:
    uint64_t s[4]={23478234234,2342342345,234234121323,2234453453};

    uint64_t seed_ = 777; /* The state can be seeded with any value. */

public:

    static inline uint64_t rotl(const uint64_t x, int k) 
    {
        return (x << k) | (x >> (64 - k));
    }


    uint64_t SplitMix64_next(void) 
    {
        uint64_t z = (seed_ += 0x9e3779b97f4a7c15);
        z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
        z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
        return z ^ (z >> 31);
    }
    void set_seed(uint64_t seed)
    {
        seed_ = seed;
    }

    void set_default()
    {
        // s[4]={SplitMix64_next(),SplitMix64_next(),SplitMix64_next(),SplitMix64_next()};
        s[0] = 23478234234;
        s[1] = 2342342345;
        s[2] = 234234121323;
        s[3] = 2234453453;
    }

    void set_s()
    {
        // s[4]={SplitMix64_next(),SplitMix64_next(),SplitMix64_next(),SplitMix64_next()};
        s[0] = SplitMix64_next();
        s[1] = SplitMix64_next();
        s[2] = SplitMix64_next();
        s[3] = SplitMix64_next();
    }

    void pprint(void)
    {
        for (int i=0; i<4 ; i++)
        {
            std::cout << s[i] << std::endl;
        }

    }

    // static uint64_t s[4]={23478234234,2342342345,234234121323,2234453453};

    double next(void) {
        //const uint64_t result = s[0] + s[3];
        const uint64_t result = ((s[0] + s[3])&0x000FFFFFFFFFFFFF)|0x3FF0000000000000;

        const uint64_t t = s[1] << 17;

        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];

        s[2] ^= t;

        s[3] = rotl(s[3], 45);
        double a;
        memcpy(&a,&result,8);
        a-=1;
        return a;
    }


    /* This is the jump function for the generator. It is equivalent
    to 2^128 calls to next(); it can be used to generate 2^128
    non-overlapping subsequences for parallel computations. */

    void jump(void) {
        static const uint64_t JUMP[] = { 0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c };

        uint64_t s0 = 0;
        uint64_t s1 = 0;
        uint64_t s2 = 0;
        uint64_t s3 = 0;
        for(int i = 0; i < sizeof JUMP / sizeof *JUMP; i++)
            for(int b = 0; b < 64; b++) {
                if (JUMP[i] & UINT64_C(1) << b) {
                    s0 ^= s[0];
                    s1 ^= s[1];
                    s2 ^= s[2];
                    s3 ^= s[3];
                }
                next();	
            }
            
        s[0] = s0;
        s[1] = s1;
        s[2] = s2;
        s[3] = s3;
    }


    /* This is the long-jump function for the generator. It is equivalent to
    2^192 calls to next(); it can be used to generate 2^64 starting points,
    from each of which jump() will generate 2^64 non-overlapping
    subsequences for parallel distributed computations. */

    void long_jump(void) {
        static const uint64_t LONG_JUMP[] = { 0x76e15d3efefdcbbf, 0xc5004e441c522fb3, 0x77710069854ee241, 0x39109bb02acbe635 };

        uint64_t s0 = 0;
        uint64_t s1 = 0;
        uint64_t s2 = 0;
        uint64_t s3 = 0;
        for(int i = 0; i < sizeof LONG_JUMP / sizeof *LONG_JUMP; i++)
            for(int b = 0; b < 64; b++) {
                if (LONG_JUMP[i] & UINT64_C(1) << b) {
                    s0 ^= s[0];
                    s1 ^= s[1];
                    s2 ^= s[2];
                    s3 ^= s[3];
                }
                next();	
            }
            
        s[0] = s0;
        s[1] = s1;
        s[2] = s2;
        s[3] = s3;
    }




};

int main () 
{
    clock_t time_req;
    time_req = clock();
    double time;
    // changing the seed for the random numbergenerator 
    // constexpr std::uint64_t Seed = 777;
    // Random_Set_Seed(Seed);

    seed_ = 777;
    // static uint64_t s[4]={23478234234,2342342345,234234121323,2234453453};
    // static uint64_t s[4]={SplitMix64_next(),SplitMix64_next(),SplitMix64_next(),SplitMix64_next()};

    Rando_Bandieto rando = Rando_Bandieto();
    // rando.pprint();
    // std::cout << "NOW" << std::endl;
    // for (int i=0; i<5 ; i++)
    // {
    //     std::cout << rando.next() << std::endl;
    // }
    // rando.set_default();
    // std::cout << "NOW" << std::endl;
    // for (int i=0; i<5 ; i++)
    // {
    //     std::cout << rando.next() << std::endl;
    // }

    // rando.set_s();
    // std::cout << "NOW" << std::endl;
    // for (int i=0; i<5 ; i++)
    // {
    //     std::cout << rando.next() << std::endl;
    // }
    // rando.pprint();






    // std::array<std::uint64_t, 4> seeds_ = seeder_<4>();
    // for (int i=0; i<SplitMix64_seeds_.size() ; i++)
    // {
    //     std::cout << SplitMix64_seeds_[i] << std::endl;
    // }


    time_req = clock();
    for(int i=0;i<100000000;++i){rando.next();}
    time_req = clock() - time_req;
    time = (float)time_req/CLOCKS_PER_SEC;
    std::cout<< "100 000 000 random numbers (RandomUniform) took "<<time<<" Seconds"<<std::endl;
    std::cout<< "Per loop is  "<<(time/100000000)*1e9<<" nano seconds"<<std::endl;


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

