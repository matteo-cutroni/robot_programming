#include "mat_f.h"
#include <assert.h>
#include <iostream>

using namespace std;

//default ctor
MatF::MatF():
  rows(0),
  cols(0),
  dimension(0),
  v(nullptr){}

// ctor with dim
MatF::MatF(int rows_, int cols_):
  rows(rows_),
  cols(cols_),
  dimension(rows*cols),
  v(new float[dimension]){}

// copy ctor
MatF::MatF(const MatF& other):
  MatF(other.rows, other.cols){
  for (int i=0; i<dimension; ++i)
    v[i]=other.v[i];
}

//dtor
MatF::~MatF() {
  if (dimension)
    delete [] v;
}

void MatF::fill(float f) {
  for (int i=0; i<dimension; ++i)
    v[i]=f;
}

void MatF::randFill() {
  for (int i=0; i<dimension; ++i)
    v[i]=drand48();
}

// read/write access to element at pos
float& MatF::at(int pos) {
  return v[pos];
}
  
// read access to element at pos
// const after () means that the method does not modify the invoking object
const float& MatF::at(int pos) const {
  return v[pos];
}

// read/write access to element at pos
float& MatF::at(int r, int c) {
  return v[r*cols+c];
}
  
// read access to element at pos
// const after () means that the method does not modify the invoking object
const float& MatF::at(int r, int c) const {
  return v[r*cols+c];
}

//op =, deep copy
MatF& MatF::operator =(const MatF& other) {
  // TODO: fillme

  return *this;
}

//returns the sum this + other
MatF MatF::operator + (const MatF& other) const {
  assert (other.cols==cols && other.rows==rows && "dim mismatch");
  MatF returned (*this);

  // TODO: fillme DONE
  for (int i; i<dimension; i++) returned.at(i) += other.at(i);
  return returned;
}

//returns the difference this - other
MatF MatF::operator - (const MatF& other) const {
  assert (other.cols==cols && other.rows==rows && "dim mismatch");
  MatF returned (*this);
  // TODO: fillme DONE
  for (int i; i<dimension; i++) returned.at(i) -= other.at(i);
  return returned;
}  


// returns this*f
MatF  MatF::operator* (float f) const {
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
  assert (other.cols==cols && other.rows==rows && "dim mismatch");
>>>>>>> 1cccbd5 (secondo esercizio)
=======
>>>>>>> 5f7bf5d (pre merge)
=======
=======
  assert (other.cols==cols && other.rows==rows && "dim mismatch");
>>>>>>> 1cccbd5 (secondo esercizio)
>>>>>>> f2a5d27 (secondo esercizio)
=======
>>>>>>> 5f7bf5d (pre merge)
=======
=======
  assert (other.cols==cols && other.rows==rows && "dim mismatch");
>>>>>>> 1cccbd5 (secondo esercizio)
>>>>>>> f2a5d27 (secondo esercizio)
  MatF returned (*this);
  // TODO: fillme DONE
  for (int i; i<dimension; i++) returned.at(i) *= f;
  return returned;
}

// returns this* other
VecF  MatF::operator* (const VecF& other) const {
  assert(other.dim==cols && "dim mismatch");
  VecF returned (rows);
  // TODO: fillme
  for (int i=0; i<rows; ++i) {
    float acc = 0.0f;
    for (int c=0; c<cols; ++c){
      acc += at(i,c)*other.at(c);
    }
    returned.at(i) = acc;
  }
  return returned;
}

  // returns this* other
MatF  MatF::operator* (const MatF& other) const {
  assert(cols==other.rows && "dimension mismatch");
  MatF returned(rows, other.cols);
  //TODO: fillme
  
  return returned;
}

MatF MatF::transpose() const {
  MatF returned(cols, rows);
  for (int r=0; r<rows; ++r)
    for (int c=0; c<cols; ++c)
      returned.at(c,r)=at(r,c);
  return returned;
}


std::ostream& operator << (std::ostream& os, const MatF& m) {
  os << "{ ptr: " << &m <<", rows: " << m.rows << ",  cols: " << m.cols << endl;
  os << "  values:[ " << endl;
  for (int r=0; r<m.rows; ++r) {
    os << "\t";
    for (int c=0; c<m.cols; ++c) {
      os << m.at(r,c) <<  " ";
    }
    os << endl;
  }
  os << " ]" << endl << "}";
  return os;
      
}
