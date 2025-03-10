#ifndef RUBIKS_CUBE_SOLVER_PATTERNDATABASE_H
#define RUBIKS_CUBE_SOLVER_PATTERNDATABASE_H

#include "../RubiksCube.h"
#include "NibbleArray.h"
#include "bits/stdc+.h"

using namespace std;

class PatternDatabase{
    NibbleArray Database;
    size_t size;
    size_t numsItems;

    PatternDatabase();
    public:
    PatternDatabase(const size_t size);
    
    PatternDatabase(const size_t size,uint8_t init_val);

    virtual uint32_t getDatabaseIndex(const RubiksCube &cube)const=0;
    virtual bool setNumMoves(const RubiksCube&cube,const uint8_t NumMoves);
    virtual bool setNumMoves(const uint8_t index,const uint8_t NumMoves);
    virtual uint8_t getNumMoves(const RubiksCube &cube)const;
    virtual uint8_t getNumMoves(const uint32_t ind)const;
    virtual size_t getSize()const;
    virtual size_t getNumItems()const;
    virtual bool isFull()const;
    virtual void toFile(const string &filePath)const;
    virtual bool fromFile(const string &filePath);
    virtual vector<uint8_t>inflate()const;
    virtual void reset();

};
#endif