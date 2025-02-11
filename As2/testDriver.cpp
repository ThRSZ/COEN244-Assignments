/*
 * testDriver.cpp
 *
 *  Created on: Sep. 26, 2024
 *      Author: umroot
 */

#include "basePlusCommission.h"
#include "commission.h"
#include <iostream>
using namespace std;

void testBaseObject(){
	CommissionEmployee comMember //base class
	("hkl","yui","4567890234",350000, 0.35);
	cout << comMember.toString() << endl;
}

void testDerivedObject(){

	BasePlusCommissionEmployee basePlusMember //derived class
	 ("abc","def","0987654321",250000, 0.15, 5000);

	cout << basePlusMember.toString() << endl;

}

int main(){
	cout<<"------------test base object--------------------"<<endl;
	testBaseObject();
	cout<<"\n------------test derived object--------------------"<<endl;
	testDerivedObject();
}

