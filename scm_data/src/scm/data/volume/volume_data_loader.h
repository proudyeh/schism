
// Copyright (c) 2012 Christopher Lux <christopherlux@gmail.com>
// Distributed under the Modified BSD License, see license.txt.

#ifndef SCM_DATA_VOLUME_LOADER_DATA_H_INCLUDED
#define SCM_DATA_VOLUME_LOADER_DATA_H_INCLUDED

//#include <fstream>

#include <scm/core/io/fstream.h>
#include <scm/core/math/math.h>

#include <scm/data/volume/scm_vol/scm_vol.h>

#include <scm/data/analysis/regular_grid_data_3d.h>
#include <scm/data/analysis/regular_grid_data_3d_write_accessor.h>

#include <scm/core/platform/platform.h>
#include <scm/core/utilities/platform_warning_disable.h>

namespace scm {
namespace data {

class __scm_export(data) volume_data_loader : public scm::data::regular_grid_data_3d_write_accessor<unsigned char>
{
public:
    volume_data_loader();
    virtual ~volume_data_loader();

    virtual bool        open_file(const std::string& filename)              = 0;
    virtual void        close_file();
    virtual bool        is_file_open() const;
    
    virtual const volume_file_descriptor&    get_volume_descriptor() const;
    //virtual const math::vec3ui_t& get_dataset_dimensions() const;

    virtual bool        read_volume(scm::data::regular_grid_data_3d<unsigned char>& target_data) = 0;
    virtual bool        read_volume_data(unsigned char*const buffer);

    virtual bool        read_sub_volume(const scm::math::vec3ui& offset,
                                        const scm::math::vec3ui& dimensions,
                                        scm::data::regular_grid_data_3d<unsigned char>& target_data) = 0; 

    virtual bool        read_sub_volume_data(const scm::math::vec3ui& offset,
                                             const scm::math::vec3ui& read_dimensions,
                                             const scm::math::vec3ui& buffer_dimensions,
                                             unsigned char*const buffer);

protected:


    io::file                _file;
    //io::ifstream            _file;

    volume_file_descriptor  _vol_desc;
    //math::vec3ui_t          _dimensions;

    //unsigned                _num_channels;
    //unsigned                _byte_per_channel;

    scm::int64              _data_start_offset;

private:

}; // namespace volume_data_loader

} // namespace data
} // namespace scm

#include <scm/core/utilities/platform_warning_enable.h>

#endif // SCM_DATA_VOLUME_LOADER_DATA_H_INCLUDED
