
// Copyright (c) 2012 Christopher Lux <christopherlux@gmail.com>
// Distributed under the Modified BSD License, see license.txt.

#ifndef SCM_DATA_SCM_GEOM_H_INCLUDED
#define SCM_DATA_SCM_GEOM_H_INCLUDED

#include <istream>
#include <ostream>
#include <string>

#include <scm/core/math/math.h>

#include <scm/core/platform/platform.h>
#include <scm/core/utilities/platform_warning_disable.h>

namespace scm {
namespace data {

class __scm_export(data) geometry_descriptor
{
public:
    geometry_descriptor();
    virtual ~geometry_descriptor();

    geometry_descriptor(const geometry_descriptor& /*rhs*/);
    const geometry_descriptor& operator=(const geometry_descriptor&  /*rhs*/);

    scm::math::vec3f    _geometry_origin;
    scm::math::vec3f    _geometry_scale;

    std::string         _sobj_file;
    std::string         _name;

    const unsigned      _version;
}; // class geometry_descriptor

__scm_export(data) std::ostream& operator<<(std::ostream& /*os*/, const geometry_descriptor& /*desc*/);
__scm_export(data) std::istream& operator>>(std::istream& /*i*/, geometry_descriptor& /*desc*/);


} // namespace data
} // namespace scm

#include <scm/core/utilities/platform_warning_enable.h>

#endif // SCM_DATA_SCM_GEOM_H_INCLUDED
