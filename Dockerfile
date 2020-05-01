FROM archlinux/base
RUN touch /foo
RUN pacman --noconfirm -Sy
RUN pacman --noconfirm -Syu
RUN pacman --noconfirm -S git base-devel cmake ffmpeg tar less findutils diffutils grep sed util-linux vim 
RUN pacman --noconfirm -S opencv opencv-samples
RUN pacman --noconfirm -S vtk qt5-base
RUN pacman --noconfirm -S hdf5
RUN pacman --noconfirm -S glew
RUN ln -s /usr/sbin/vim /usr/sbin/vi
ENV TZ Europe/London
RUN echo $TZ > /etc/timezone

RUN useradd -m ad
RUN echo 'ad:ad' | chpasswd
RUN echo "ad ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers
USER ad
WORKDIR /home/ad

COPY Makefile Makefile
COPY moco.cpp moco.cpp
RUN make

ENTRYPOINT ["/home/ad/moco"]
