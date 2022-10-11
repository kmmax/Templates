#include <iostream>
#include <string>
#include <sstream>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

using std::cout;
using std::endl;


// Constants
const std::string DEFAULT_HOST = "127.0.0.1";	//< Host IP
const int DEFAULT_PORT = 502;					//< Host Port
const uint16_t DEFAULT_SLAVE_ID = 1;			//< Device ID
const uint16_t DEFAULT_REGISTER_ADDRESS = 1;	//< Address of first register
const uint16_t DEFAULT_REGISTERS_NUMBER = 1;	//< Number of registers for reading


int main(int argc, char** argv)
{
    po::options_description cmdline_options;
    po::options_description desc("Allowed options");

    int port;
    int register_number;
    std::string host = "localhost";
    uint16_t register_address;
    uint16_t slave;
    int number;

    desc.add_options()
        ("help,h", "produce help message")
        ("host", po::value<std::string>(&host)->default_value(DEFAULT_HOST), "host (default 127.0.0.1)")    //        ("host", po::value<std::string>(), "host") - without option
        ("port,p", po::value<int>(&port)->default_value(DEFAULT_PORT), "tcp port (default 502)")
        ("slave,s", po::value<uint16_t>(&slave)->default_value(DEFAULT_SLAVE_ID), "slave id (default 1")
        ("address,a", po::value<uint16_t>(&register_address)->default_value(DEFAULT_REGISTER_ADDRESS), "register address (default 1)")
        ("number,n", po::value<int>(&register_number)->default_value(DEFAULT_REGISTERS_NUMBER), "number of registers (default 1)")
        ;
    cmdline_options.add(desc);

    po::positional_options_description p;
    p.add("host", -1);
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(cmdline_options).positional(p).run(), vm);
    po::notify(vm);

    if (vm.count("help") || vm.count("host") == 0) {
        std::cout << cmdline_options;
        return 0;
    }

    if (vm.count("host"))
        host = vm["host"].as<std::string>();


    cout << "Parameters:" << endl;
    cout << "\tHOST: " << vm["host"].as<std::string>() << endl;;
    cout << "\tPORT: " << vm["port"].as<int>() << endl;
    cout << "\tSLAVE: " << static_cast<unsigned int>(vm["slave"].as<uint16_t>()) << endl;
    cout << "\tADDRESS: " << static_cast<unsigned int>(vm["address"].as<uint16_t>()) << endl;
    cout << "\tNUMBER: " << vm["number"].as<int>() << endl;

	return 0;

}
