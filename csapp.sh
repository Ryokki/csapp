DEBIAN_FRONTEND=noninteractive
apt-get -y update
apt-get -y install git
apt-get -y install wget
apt-get -y install sudo
sudo apt-get install gcc-multilib -y
wget https://gitee.com/lin-xi-269/tools/raw/master/os/QHubuntu20.04 && bash QHubuntu20.04
apt-get install build-essential -y

wget https://gitee.com/lin-xi-269/csapplab/raw/origin/installAll.sh
bash installAll.sh
apt-get install python2 -y

cd csapplab/archlab/archlab-handout/
tar -xvf sim.tar
cd sim/pipe/
wget https://gitee.com/lin-xi-269/csapplab/raw/master/lab4archlab/archlab-handout/sim/pipe/run.sh
chmod +x run.sh

wget https://gitee.com/lin-xi-269/csapplab/raw/master/lab4archlab/archlab-handout/installTclTk.sh && bash installTclTk.sh

# lab8 proxy
apt-get install net-tools

# 如果 需要 cgdb 工具 的话，可以打开注释 lab2 或许需要
# wget https://gitee.com/lin-xi-269/csapplab/raw/master/lab2bomb/installCgdb.sh
# bash installCgdb.sh
