Start menu: QMK MSYS
go to qmk_firmware directory

Make:
    
	make bfb/midi88:default

After which, drop bfb_midi88_default.uf2 into the keyboard
sitting in a bootloader mode (press Row0 Col0 while plugging in)

https://docs.qmk.fm/#/getting_started_build_tools 
https://docs.qmk.fm/#/getting_started_make_guide
https://docs.qmk.fm/#/newbs

1. Press and hold    Boot
2. Press and release NRST
3. Release           Boot

(if there are unknown issues - try updating QMK MSYS:  git pull --recurse-submodules) 

