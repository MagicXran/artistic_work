//
// Created by Administrator on 29/03/2022.
//

#ifndef INSPIRATION_FILE_MAPPED_HPP
#define INSPIRATION_FILE_MAPPED_HPP

#include <boost/interprocess/file_mapping.hpp>
#include <boost/interprocess/mapped_region.hpp>

class MappingFile {
public:
    static void mapping(const char *filename);
};

inline void MappingFile::mapping(const char *file) {
    using namespace boost::interprocess;
    file_mapping m_file(file , read_write);
    std::size_t FileSize = 20;
    //Map the second half of the file
    mapped_region region(m_file                   //Memory-mappable object
            , read_write               //Access mode
//            , FileSize / 2               //Offset from the beginning of shm
//            , FileSize - FileSize / 2      //Length of the region
    );

//Get the address of the region
    std::cout << "region.get_address(): " << region.get_address() << std::endl;

//Get the size of the region
    std::cout << "region.get_size(): " << region.get_size() << std::endl;

//    memset(region.get_address() , 0x03 , region.get_size());
    auto addr = region.get_address();
    sprintf_s(static_cast<char *>(addr) , region.get_size() , "%s" , " you like me 我就是我 i love you ");
    //Flush the whole region
    std::cout << region.flush() << std::endl;

//Flush from an offset until the end of the region
//    region.flush();

//Flush a memory range starting on an offset
//    region.flush(size);

}

#endif //INSPIRATION_FILE_MAPPED_HPP
