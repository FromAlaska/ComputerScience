//
//  SmartArayy.hpp
//  Spring2017CS202SmartArray
//
//  Created by Chris Hartman on 3/2/17.
//  Copyright © 2017 Chris Hartman. All rights reserved.
//

#ifndef SmartArray_hpp
#define SmartArray_hpp

class SmartArray {
public:
    SmartArray(int);
    SmartArray(const SmartArray &);
    ~SmartArray();
    int & operator[](int);
    int operator[](int) const;
    SmartArray & operator=(const SmartArray &);
    int size() const;
private:
    int *_data;
    int _size;
};
#endif /* SmartArray_hpp */
