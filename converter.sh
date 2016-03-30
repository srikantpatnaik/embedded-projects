cp -v ~/kazam_00000.mp4 /tmp

avconv -y -i /tmp/kazam_00000.mp4 -b:v 500k -r 15 -strict experimental /tmp/normal-size.mp4

avconv -y -i /tmp/normal-size.mp4 /tmp/stereo-noisy.wav

audacity /tmp/stereo-noisy.wav

avconv -y -i /tmp/normal-size.mp4 -i /tmp/stereo-noisefree.mp3 -map 0:0 -map 1 -vcodec copy -strict experimental /tmp/output.mp4

# To add multiple mp4 files to output.mp4
#MP4Box -cat kazam_00000.mp4 -cat beta-videos/5.3_solder-16x2.mp4 -cat kazam_00001.mp4 -new output.mp4

# To cut portion of mp4 video, here from 0s to 4m55s
#avconv -ss 00:00:00.00 -i kazam_00000.mp4 -t 00:04:55.10 -acodec copy -vcodec copy out.mp4

# To cut till end just don't provide the duration (-t).
#avconv -ss 00:00:00.00 -i kazam_00000.mp4 -acodec copy -vcodec copy out.mp4

# To slow down the video/audio together
#mencoder -ovc copy -oac pcm -speed .95 fast.webm -o slow.webm

# Join mkv videos
