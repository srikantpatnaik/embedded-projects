avconv -i /tmp/kazam_00000.mp4 -b:v 500k -r 15 -strict experimental /tmp/normal-size.mp4

avconv -i /tmp/normal-size.mp4 /tmp/stereo-noisy.wav

#avconv -i /tmp/normal-size.mp4 -i stereo-noisefree.mp3 -map 0:0 -map 1 -vcodec copy -strict experimental /tmp/output.mp4
