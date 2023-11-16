#ifndef FONTCONFIG_HPP
#define FONTCONFIG_HPP

#include "fontconfig/fontconfig.h"
#include "boost/intrusive_ptr.hpp"
#include <boost/smart_ptr/intrusive_ptr.hpp>

template <auto AddRef, class T>
void intrusive_ptr_add_ref(T* p) {
    AddRef(p);
}

template <auto Release, class T>
void intrusive_ptr_release(T* p) {
    Release(p);
}

template<>
void intrusive_ptr_add_ref<FcPatternReference, FcPattern>(FcPattern* p);

namespace fontconfig {
    using Patern = boost::intrusive_ptr<FcPattern>;
}

#endif