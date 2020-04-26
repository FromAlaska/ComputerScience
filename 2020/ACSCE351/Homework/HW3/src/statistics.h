/*
Compute statistics (mean, variance, standard deviation)
of a set of samples.  Also includes calculation routines
for a few distributions.

Orion's Standard Library
written by 
Orion Sky Lawlor, olawlor@acm.org, 2/24/2002
*/
#ifndef __OSL_STATISTICS_H
#define __OSL_STATISTICS_H

#include "math.h" //for sqrt

namespace osl { namespace statistics {

/* A sample of n items; to compute means and variances. */
template<class real,class ret>
class SampleT {
	real sum; //sum of values
	real sq; //sum of squares
	int n; //number of values
public:
	SampleT(void) {
		sum=sq=0;
		n=0;
	}
	inline int size(void) const { return n; }
	inline void add(real r) {
		sum+=r;
		sq+=r*r;
		n++;
	}
	inline void operator+=(real r) { add(r); }
	ret getMean(void) const {
		return (ret)((ret)(sum)/n);
	}
	ret getVariance(void) const {
		return (ret)((sq-(ret)(sum)*sum/n)/(n-1));
	}
	real getStddev(void) const {
		return (real)sqrt(getVariance());
	}
};
typedef SampleT<double,double> Sample;


/*Return the factorial of n*/
double fact(int n) {
	register double ret=1;
	while (n>1) {
		ret*=n;
		n--;
	}
	return ret;
}

/*
Return the number of ways to choose x items out of n.
That is, "n choose x".  This is equal to:
     n!
 -----------
  x! (n-x)!
or
  n*(n-1)*(n-2)*...*(n-x+1)
 ---------------------------
  x*(x-1)*(x-2)*...*   1
*/
double comb(int n,int x)
{
	if (x*2>n) x=n-x; //Use the smaller version of x
	double ret=1.0;
	for (int i=0;i<x;i++)
		ret*=(n-i)/(double)(x-i);
	return ret;
}

/*
Return the probability of x successes out of n trials
if each trial succeeds with probability p.
Probably a bit roundoff-sensitive for large n and small p.
*/
double binom(int x,int n,double p)
{
	return comb(n,x)*pow(p,x)*pow(1.0-p,n-x);
}

}; };


#endif //def(thisHeader)

