//this is the definition for a random number generator class that will be used in the dice rolling facility
#ifndef RANDOM_NUMBER_GENERATOR_H
#define RANDOM_NUMBER_GENERATOR_H

class RandomNumberGenerator
{
  //the random number generator class
  //based on a linear congruential PRNG that I originally created in java

  private:
    long seed; //the seed for the random number generator
    static long MULTIPLIER;
    static long CONSTANT;
    static long MODULUS;

  public:
    RandomNumberGenerator(); //default constructor
    RandomNumberGenerator(long); //constructor that accepts an initial seed value
    ~RandomNumberGenerator(); //destructor
};

#endif