# shell

## Compile

    cmake .
    make
    ./shell

## Usage

    $ ./shell
    $ date
    2014年 12月25日 木曜日 23時06分04秒 JST
    $ whoami
    ek
    $ echo lol cat
    lol cat
    $ ping -c 3 8.8.8.8
    PING 8.8.8.8 (8.8.8.8): 56 data bytes
    64 bytes from 8.8.8.8: icmp_seq=0 ttl=52 time=5.050 ms
    64 bytes from 8.8.8.8: icmp_seq=1 ttl=52 time=4.926 ms
    64 bytes from 8.8.8.8: icmp_seq=2 ttl=52 time=4.944 ms
    
    --- 8.8.8.8 ping statistics ---
    3 packets transmitted, 3 packets received, 0.0% packet loss
    round-trip min/avg/max/stddev = 4.926/4.973/5.050/0.055 ms
    $ history
    0	date
    1	whoami
    2	echo lol cat
    3	ping -c 3 8.8.8.8
    $ exit

## Features

* Fu**ing shell (untested dirty code)
* Command history (type **history** command)
* Tab completion (NOT implemented YET)
