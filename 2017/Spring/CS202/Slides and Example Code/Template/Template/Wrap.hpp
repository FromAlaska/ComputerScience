//
//  Wrap.hpp
//  Playground
//
//  Created by Chris Hartman on 4/13/17.
//  Copyright © 2017 Chris Hartman. All rights reserved.
//

#ifndef Wrap_hpp
#define Wrap_hpp

template <typename Objtype>
class Wrap {
public:
    ~Wrap();
    Wrap();
    Wrap(const Objtype &);
    Objtype & operator*();
private:
    Objtype * _ptr;
};

template <typename Objtype>
Wrap<Objtype>::~Wrap() {
    delete _ptr;
}

template <typename Objtype>
Wrap<Objtype>::Wrap() :_ptr(new Objtype) {
}

template <typename Objtype>
Wrap<Objtype>::Wrap(const Objtype &o) :_ptr(new Objtype(o)) {
}

template <typename Objtype>
Objtype & Wrap<Objtype>::operator*() {
    return *_ptr;
}

template <typename Objtype>
Wrap<Objtype> make_wrap(const Objtype &o) {
    return Wrap<Objtype>{o};
}
#endif /* Wrap_hpp */
