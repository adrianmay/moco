SRC=moco.cpp
TGT=moco

$(TGT): $(SRC)
	g++ $(SRC) -o $(TGT) -I /usr/include/opencv4 -lopencv_viz -lopencv_phase_unwrapping -lopencv_superres -lopencv_java430 -lopencv_bioinspired -lopencv_rapid -lopencv_video -lopencv_fuzzy -lopencv_ml -lopencv_plot -lopencv_videostab -lopencv_structured_light -lopencv_xfeatures2d -lopencv_line_descriptor -lopencv_dnn_objdetect -lopencv_core -lopencv_stereo -lopencv_intensity_transform -lopencv_dnn_superres -lopencv_optflow -lopencv_cvv -lopencv_imgproc -lopencv_tracking -lopencv_dnn -lopencv_gapi -lopencv_face -lopencv_rgbd -lopencv_photo -lopencv_xobjdetect -lopencv_stitching -lopencv_ximgproc -lopencv_quality -lopencv_imgcodecs -lopencv_features2d -lopencv_dpm -lopencv_saliency -lopencv_surface_matching -lopencv_reg -lopencv_text -lopencv_flann -lopencv_calib3d -lopencv_xphoto -lopencv_hdf -lopencv_datasets -lopencv_ccalib -lopencv_aruco -lopencv_alphamat -lopencv_img_hash -lopencv_videoio -lopencv_objdetect -lopencv_freetype -lopencv_bgsegm -lopencv_hfs -lopencv_highgui -lopencv_shape

