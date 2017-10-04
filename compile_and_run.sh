 dir_name=${PWD##*/}
 
 function build_and_run(){
    cmake .. && make && ./open_gl_display
 }
 

if [ dir_name -eq "build" ];then

    build_and_run

else

    # Create the build directory if it doesn't exist
    if [ -d "build" ]; then
        cd build
    elif [ ! -d "build" ]; then
        mkdir build
        cd build
    fi
        
    # Now the build directory exists, build and run
    # then go back to the previous directory
    build_and_run
    cd - > /dev/null
fi