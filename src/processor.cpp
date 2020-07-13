#include "processor.h"

Processor::Processor() {

    tAll_ = LinuxParser::Jiffies();
    tIdle_ = LinuxParser::IdleJiffies();
}

// Return the aggregate CPU utilization
float Processor::Utilization() { 
    
    float tAllOLd = tAll_;
    float tIdleOld = tIdle_;        

    tAll_ = LinuxParser::Jiffies();
    tIdle_ = LinuxParser::IdleJiffies();    
    
    float cpu_utilization = ((( tAll_ - tAllOLd) - (tIdle_ - tIdleOld)) / (tAll_ - tAllOLd));
    return (cpu_utilization > 0.0) ? cpu_utilization : 0.0; 
}