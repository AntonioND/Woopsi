#include <nds.h>
#include "bittest4.h"

using namespace WoopsiUI;

static const u16 bittest4_Bitmap[2576] __attribute__ ((aligned (4))) = {
47667, 53940, 56053, 51826, 45553, 44529, 39179, 34855, 37000, 41259, 45486, 
53908, 59159, 58102, 57078, 53941, 43381, 38101, 37108, 38100, 37076, 37076, 
37075, 37075, 38099, 37075, 36051, 50807, 63452, 64476, 64508, 57114, 38132, 
36051, 45493, 61275, 62331, 46551, 37075, 39156, 58138, 65531, 65532, 63451, 
49687, 37077, 37077, 38133, 40246, 44473, 47609, 48667, 46587, 45530, 53944, 
60282, 50805, 48690, 47633, 44496, 38120, 33858, 39210, 42416, 43473, 43472, 
50802, 59189, 56877, 46341, 46408, 46406, 45518, 47667, 46643, 45587, 46643, 
46644, 47565, 44260, 47563, 45350, 51592, 41162, 34889, 33863, 34887, 33863, 
33862, 33861, 33828, 32802, 50636, 53737, 60146, 59191, 47665, 46610, 38123, 
37002, 51763, 58103, 58135, 59223, 59159, 57045, 52884, 44435, 38099, 36052, 
37075, 37043, 37075, 37075, 37075, 37074, 37074, 37042, 39188, 59226, 64508, 
65532, 63419, 46582, 36019, 36051, 36019, 44437, 45526, 38099, 37075, 37044, 
45494, 62395, 65532, 65532, 58139, 38133, 37076, 38133, 38133, 40246, 42359, 
44440, 45530, 46587, 45498, 52889, 61305, 52917, 44496, 43440, 39210, 33891, 
39178, 43473, 43473, 44496, 53940, 59124, 49477, 39075, 42314, 39042, 44429, 
45586, 45587, 46611, 45587, 47667, 43371, 35905, 41191, 36995, 49508, 49548, 
35978, 33863, 34887, 33862, 33828, 33826, 33826, 33826, 44325, 47495, 55852, 
61271, 49746, 46610, 37066, 46512, 64445, 65535, 65535, 65535, 65535, 65535, 
65535, 65535, 64479, 57116, 49720, 36019, 37075, 37043, 43381, 59196, 65535, 
65535, 60285, 63420, 64507, 65531, 58170, 39220, 37043, 39187, 38131, 36019, 
37075, 37043, 42357, 40212, 38164, 57081, 65532, 65532, 62363, 41301, 37076, 
37076, 38101, 38133, 39190, 41303, 44473, 45530, 44474, 45497, 54999, 50772, 
42383, 40301, 39210, 33891, 38120, 43472, 44497, 44497, 53907, 59090, 47396, 
33792, 35905, 35905, 41324, 45554, 45554, 46578, 45555, 47666, 42315, 35873, 
37888, 34848, 46371, 57966, 44397, 34887, 33862, 32837, 32834, 33825, 33824, 
33857, 36929, 40133, 50599, 61271, 49747, 45553, 44430, 64478, 65535, 65535, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 60253, 40212, 
43381, 65535, 65535, 65535, 65535, 65535, 65535, 64475, 64509, 61341, 65535, 
59196, 52889, 50775, 38131, 37043, 41300, 58137, 48663, 37075, 45494, 62362, 
65532, 64475, 43413, 37076, 37077, 37076, 37077, 37109, 39190, 41271, 43385, 
43417, 42362, 44472, 46611, 42383, 41359, 38153, 33858, 36006, 43472, 44529, 
44496, 50802, 59091, 47396, 36864, 39936, 37954, 42381, 46642, 46644, 46675, 
45620, 46643, 43372, 36897, 41984, 37920, 48453, 62194, 57077, 39146, 34884, 
33828, 33858, 33857, 33857, 33825, 39011, 35872, 52681, 59190, 48724, 43439, 
52852, 65535, 57087, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 34911, 
43359, 59199, 65535, 59229, 50776, 65535, 50751, 32799, 32799, 57087, 65535, 
65534, 65535, 65535, 65535, 65535, 64479, 61338, 45525, 38131, 51831, 64475, 
54968, 38099, 39188, 56057, 65532, 64475, 44470, 37076, 37076, 37076, 37076, 
37077, 38134, 39190, 40248, 41336, 42361, 42330, 43445, 42383, 41358, 37096, 
33857, 36005, 43473, 44529, 44497, 48721, 58100, 50568, 37920, 40035, 46509, 
52951, 55130, 55131, 55130, 55097, 51927, 46609, 39043, 37888, 38976, 53705, 
61237, 59190, 46576, 38089, 34851, 33826, 33857, 33825, 34881, 55031, 50670, 
60081, 54997, 48692, 39210, 51827, 65535, 57087, 32799, 32799, 32799, 32799, 
32799, 32799, 32799, 32799, 32799, 34911, 59199, 65535, 49752, 65535, 50751, 
32799, 32799, 57087, 65535, 65535, 61311, 41247, 32799, 57087, 65535, 65532, 
60250, 50775, 61338, 65531, 61274, 41268, 36051, 45494, 63419, 64475, 43382, 
37075, 37076, 37076, 37076, 37076, 38133, 38133, 38166, 40247, 40248, 40281, 
40281, 41329, 41358, 37063, 32800, 37063, 44530, 44530, 44530, 46609, 54964, 
55920, 46508, 49813, 53050, 55098, 56186, 57211, 58267, 58300, 58300, 57210, 
51726, 43203, 48454, 58033, 60247, 52915, 47667, 45586, 41292, 36005, 33858, 
33858, 33857, 59324, 60347, 62395, 52917, 46642, 36006, 48690, 65535, 57087, 
32799, 32799, 37023, 50751, 50751, 50751, 47583, 34911, 32799, 32799, 43359, 
65535, 59196, 65535, 52863, 41247, 41247, 59199, 65535, 65535, 57087, 32799, 
32799, 57087, 65535, 65533, 64475, 64477, 65534, 65534, 65533, 50776, 55003, 
62366, 65535, 65535, 57083, 43414, 37076, 49721, 59197, 65535, 65535, 60253, 
53947, 41303, 39191, 39224, 40249, 41301, 50805, 54998, 61307, 65535, 65535, 
65535, 61340, 55032, 51827, 53974, 54041, 58236, 62398, 62397, 59260, 60317, 
63454, 65535, 65535, 64510, 62396, 53873, 54897, 57078, 53941, 47633, 44496, 
45586, 45585, 40233, 34914, 33857, 33857, 56122, 57210, 59323, 56154, 47698, 
34948, 48657, 65535, 57087, 32799, 32799, 41247, 65535, 65535, 65535, 65535, 
57087, 32799, 32799, 32799, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
65535, 65535, 57087, 32799, 32799, 57087, 65535, 65535, 65534, 65535, 65535, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 60253, 65535, 
65535, 65535, 65535, 65535, 65535, 63423, 43384, 39191, 44473, 62366, 65535, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 64478, 52951, 65535, 65535, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 62397, 49779, 
48723, 46610, 44529, 42382, 39210, 37096, 38086, 34915, 33858, 33858, 52984, 
53017, 55097, 58235, 49779, 38120, 51828, 65535, 57087, 32799, 32799, 41247, 
65535, 58172, 50776, 65535, 65535, 32799, 32799, 32799, 65535, 65535, 65535, 
52863, 41247, 41247, 59199, 65535, 41247, 39135, 32799, 32799, 39135, 41247, 
59199, 65535, 65535, 41247, 41247, 52863, 65535, 50751, 37023, 32799, 37023, 
50751, 65535, 65535, 59199, 43359, 32799, 32799, 39135, 54975, 65535, 63423, 
42359, 65535, 65535, 57087, 45471, 37023, 32799, 32799, 32799, 41247, 54975, 
65535, 65535, 65535, 52863, 41247, 41247, 65535, 57087, 39135, 32799, 34911, 
45471, 63423, 65535, 59259, 45619, 45587, 44530, 44496, 41324, 37063, 34947, 
34914, 33858, 33858, 52984, 51960, 53016, 55097, 50870, 44429, 54998, 65535, 
57087, 32799, 32799, 41247, 65535, 65535, 65535, 65535, 57087, 32799, 32799, 
43359, 65535, 59196, 65535, 50751, 32799, 32799, 57087, 65535, 32799, 32799, 
32799, 32799, 32799, 32799, 57087, 65535, 65535, 32799, 32799, 50751, 45471, 
32799, 32799, 32799, 32799, 32799, 52863, 59199, 34911, 32799, 32799, 32799, 
32799, 32799, 54975, 65535, 57116, 65535, 52863, 32799, 32799, 32799, 32799, 
32799, 32799, 32799, 32799, 52863, 65535, 65535, 50751, 32799, 32799, 54975, 
32799, 32799, 32799, 32799, 32799, 39135, 63423, 65535, 49814, 43473, 43440, 
43472, 42416, 40267, 37030, 34915, 33891, 33858, 51895, 50903, 52952, 52984, 
51927, 49680, 56055, 65535, 57087, 32799, 32799, 37023, 50751, 50751, 50751, 
47583, 34911, 32799, 34911, 61311, 65535, 50743, 65535, 50751, 32799, 32799, 
57087, 65535, 50751, 41247, 32799, 32799, 45471, 50751, 61311, 65535, 65535, 
32799, 32799, 41247, 34911, 50751, 57087, 50751, 32799, 32799, 37023, 37023, 
41247, 54975, 54975, 43359, 32799, 32799, 39135, 65535, 65535, 63423, 34911, 
32799, 39135, 52863, 57087, 57087, 45471, 32799, 32799, 37023, 65535, 65535, 
50751, 32799, 32799, 37023, 41247, 54975, 54975, 39135, 32799, 32799, 50751, 
65535, 58170, 41358, 40301, 40302, 41359, 41358, 39178, 34948, 33891, 33890, 
49781, 49814, 50870, 51928, 50837, 48656, 56022, 65535, 57087, 32799, 32799, 
32799, 32799, 32799, 32799, 32799, 32799, 41247, 63423, 65535, 59228, 50743, 
65535, 50751, 32799, 32799, 57087, 65535, 65535, 50751, 32799, 32799, 57087, 
65535, 65535, 65535, 65535, 32799, 32799, 32799, 54975, 65535, 65535, 65535, 
45471, 32799, 32799, 41247, 65535, 65535, 65535, 65535, 37023, 32799, 32799, 
65535, 65535, 61311, 47583, 41247, 63423, 65535, 65535, 65535, 65535, 39135, 
32799, 32799, 65535, 65535, 50751, 32799, 32799, 39135, 65535, 65535, 65535, 
63423, 32799, 32799, 37023, 65535, 62397, 40301, 39276, 39244, 40268, 41325, 
40268, 34949, 33858, 33858, 47700, 47701, 48757, 50837, 46609, 48623, 57046, 
65535, 57087, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 
37023, 59199, 65535, 57082, 65535, 50751, 32799, 32799, 57087, 65535, 65535, 
50751, 32799, 32799, 57087, 65535, 45531, 65535, 65535, 32799, 32799, 37023, 
65535, 63455, 51836, 65535, 50751, 32799, 32799, 52863, 65535, 51866, 58172, 
65535, 41247, 32799, 32799, 65535, 65535, 65535, 65535, 65535, 63423, 57087, 
50751, 50751, 50751, 37023, 32799, 32799, 65535, 65535, 50751, 32799, 32799, 
52863, 65535, 57146, 61341, 65535, 43359, 32799, 32799, 61311, 65535, 44495, 
40301, 40301, 40269, 39244, 39244, 36006, 34883, 34883, 46610, 46644, 46676, 
47667, 42315, 50737, 57046, 65535, 57087, 32799, 32799, 41247, 65535, 65535, 
65535, 65535, 50751, 32799, 32799, 34911, 63423, 65535, 65535, 50751, 32799, 
32799, 57087, 65535, 65535, 50751, 32799, 32799, 57087, 65535, 46588, 65535, 
65535, 32799, 32799, 41247, 65535, 59198, 51869, 65535, 50751, 32799, 32799, 
57087, 65535, 46586, 59197, 65535, 41247, 32799, 32799, 65535, 65535, 65535, 
61311, 43359, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 65535, 
65535, 50751, 32799, 32799, 57087, 65535, 50837, 55033, 65535, 50751, 32799, 
32799, 57087, 65535, 47666, 41326, 41326, 41326, 40301, 39244, 37063, 34883, 
34915, 44529, 44530, 44529, 41323, 44460, 52851, 56022, 65535, 57087, 32799, 
32799, 41247, 65535, 65535, 65535, 65535, 65535, 45471, 32799, 32799, 52863, 
65535, 65535, 50751, 32799, 32799, 57087, 65535, 65535, 50751, 32799, 32799, 
57087, 65535, 49724, 65535, 65535, 32799, 32799, 41247, 65535, 60286, 55005, 
65535, 50751, 32799, 32799, 57087, 65535, 47644, 59230, 65535, 41247, 32799, 
32799, 65535, 65535, 61311, 34911, 32799, 34911, 47583, 57087, 65535, 65535, 
41247, 32799, 32799, 65535, 65535, 50751, 32799, 32799, 57087, 65535, 49780, 
55000, 65535, 50751, 32799, 32799, 57087, 65535, 47667, 41358, 41358, 41326, 
40268, 40268, 37096, 33891, 33858, 41325, 40266, 37062, 43405, 48690, 49748, 
52886, 65535, 57087, 32799, 32799, 41247, 65535, 58139, 49719, 54969, 65535, 
50751, 32799, 32799, 50751, 65535, 65535, 50751, 32799, 32799, 57087, 65535, 
65535, 50751, 32799, 32799, 57087, 65535, 48664, 65535, 65535, 32799, 32799, 
41247, 65535, 59228, 52889, 65535, 50751, 32799, 32799, 57087, 65535, 53949, 
61310, 65535, 41247, 32799, 32799, 65535, 65535, 45471, 32799, 32799, 57087, 
65535, 65535, 65535, 65535, 41247, 32799, 32799, 65535, 65535, 50751, 32799, 
32799, 57087, 65535, 50772, 56056, 65535, 45471, 32799, 32799, 61311, 65535, 
44496, 41358, 41325, 40268, 39211, 40267, 38119, 33890, 33858, 35971, 34947, 
40235, 47635, 47668, 46643, 48693, 65535, 57087, 32799, 32799, 41247, 65535, 
65535, 65535, 65535, 65535, 37023, 32799, 32799, 50751, 65535, 65535, 50751, 
32799, 32799, 57087, 65535, 65535, 50751, 32799, 32799, 57087, 65535, 58170, 
65535, 65535, 32799, 32799, 41247, 65535, 58137, 49683, 65535, 50751, 32799, 
32799, 57087, 65535, 47573, 60252, 65535, 41247, 32799, 32799, 65535, 65535, 
41247, 32799, 32799, 65535, 65535, 65535, 65535, 61311, 32799, 32799, 32799, 
65535, 65535, 50751, 32799, 32799, 45471, 65535, 65535, 65535, 65535, 37023, 
32799, 34911, 65535, 64478, 42383, 41326, 41325, 39243, 39243, 40268, 39177, 
34915, 33825, 41324, 42414, 46643, 48724, 46610, 44530, 46580, 65535, 57087, 
32799, 32799, 37023, 50751, 50751, 50751, 50751, 37023, 32799, 32799, 32799, 
61311, 65535, 65535, 50751, 32799, 32799, 57087, 65535, 65535, 50751, 32799, 
32799, 47583, 65535, 65535, 65535, 65535, 32799, 32799, 41247, 65535, 58137, 
48659, 65535, 50751, 32799, 32799, 57087, 65535, 42318, 58137, 65535, 41247, 
32799, 32799, 65535, 65535, 45471, 32799, 32799, 45471, 63423, 65535, 57087, 
39135, 32799, 32799, 32799, 65535, 65535, 50751, 32799, 32799, 32799, 50751, 
63423, 63423, 45471, 32799, 32799, 47583, 65535, 59227, 42415, 42382, 41325, 
39244, 39244, 40268, 39178, 34915, 32800, 44530, 47634, 52917, 56055, 45521, 
41293, 44467, 65535, 57087, 32799, 32799, 32799, 32799, 32799, 32799, 32799, 
32799, 32799, 32799, 50751, 65535, 59196, 65535, 50751, 32799, 32799, 57087, 
65535, 65535, 59199, 32799, 32799, 32799, 32799, 50751, 65535, 65535, 32799, 
32799, 41247, 65535, 58137, 48659, 65535, 50751, 32799, 32799, 57087, 65535, 
42318, 57113, 65535, 41247, 32799, 32799, 65535, 65535, 57087, 32799, 32799, 
32799, 32799, 32799, 32799, 41247, 43359, 32799, 32799, 65535, 65535, 50751, 
32799, 32799, 39135, 32799, 32799, 32799, 32799, 32799, 34911, 63423, 65535, 
51862, 43472, 42382, 41325, 40301, 40268, 40268, 40235, 34948, 32801, 44530, 
50804, 57111, 59225, 48690, 38122, 43411, 65535, 57087, 32799, 32799, 32799, 
32799, 32799, 32799, 32799, 32799, 41247, 54975, 65535, 65535, 49684, 65535, 
50751, 32799, 32799, 57087, 65535, 59194, 65535, 47583, 32799, 32799, 32799, 
50751, 65535, 65535, 32799, 32799, 41247, 65535, 58137, 48659, 65535, 50751, 
32799, 32799, 57087, 65535, 42318, 57113, 65535, 41247, 32799, 32799, 65535, 
65535, 65535, 52863, 34911, 32799, 32799, 32799, 41247, 63423, 50751, 32799, 
32799, 57087, 65535, 50751, 32799, 32799, 54975, 43359, 32799, 32799, 32799, 
37023, 59199, 65535, 62364, 51861, 44529, 41359, 41358, 41325, 40301, 41325, 
40235, 34948, 33857, 48723, 54998, 57079, 59193, 53974, 40203, 36015, 61309, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
63422, 41261, 41261, 65535, 65535, 65535, 65535, 65535, 61308, 43374, 65535, 
65535, 63423, 57087, 59199, 65535, 65535, 65535, 65535, 65535, 65535, 65535, 
49715, 41260, 65535, 65535, 65535, 65535, 65535, 61308, 34920, 49715, 65535, 
65535, 65535, 65535, 65535, 58170, 65535, 65535, 65535, 57087, 57087, 61311, 
65535, 65535, 65535, 65535, 65535, 65535, 65535, 50751, 32799, 32799, 57087, 
65535, 61311, 57087, 59199, 65535, 65535, 64510, 62395, 58168, 47634, 42416, 
41359, 41326, 40301, 40268, 39178, 34916, 33857, 52852, 57046, 57078, 60217, 
59225, 44433, 35983, 41265, 59195, 65535, 65535, 65535, 65535, 65535, 65535, 
65535, 65535, 58170, 50739, 37034, 33863, 33863, 41261, 58138, 65535, 65535, 
58137, 39112, 32803, 43339, 58169, 65535, 65535, 65535, 59226, 43373, 59194, 
65535, 65535, 59194, 50771, 37030, 35974, 42281, 58136, 65535, 65535, 58136, 
40136, 33828, 33861, 49715, 58138, 65535, 65535, 58138, 39147, 39147, 56056, 
64478, 65535, 65535, 65535, 61309, 61275, 63421, 65535, 65535, 61340, 65535, 
50751, 32799, 32799, 57087, 65535, 65535, 65535, 65535, 65535, 64477, 61305, 
61273, 61305, 52917, 44528, 43440, 42382, 40301, 40300, 38154, 34916, 33857, 
54932, 57078, 58135, 59159, 59224, 45490, 34957, 35981, 35981, 34957, 35980, 
34956, 34925, 36016, 36016, 34923, 33896, 34888, 34888, 33863, 33863, 33862, 
32837, 32803, 33826, 34849, 33824, 33824, 32768, 33825, 37029, 39210, 45520, 
44462, 39210, 39211, 40267, 40268, 39244, 39211, 39211, 39211, 38120, 34914, 
33824, 33792, 32800, 33824, 33824, 33824, 33825, 33826, 33828, 33862, 33862, 
33863, 33863, 33863, 34887, 34920, 44402, 44437, 40243, 43411, 55990, 57046, 
55989, 59159, 61274, 65535, 50751, 32799, 32799, 57087, 65535, 48723, 57144, 
63420, 62329, 61272, 59192, 60216, 61273, 57111, 45585, 44496, 42383, 40301, 
40301, 39210, 34915, 33857, 54965, 57046, 57078, 58135, 59191, 44433, 34957, 
35981, 34924, 34924, 34956, 34924, 34958, 35982, 33865, 33864, 33863, 33863, 
33863, 33862, 33829, 33826, 33793, 33792, 33824, 33824, 33824, 33824, 33824, 
33792, 36004, 40235, 40269, 41325, 41358, 42382, 42382, 42382, 42383, 41358, 
41358, 41325, 39176, 33825, 33824, 33824, 33856, 34881, 34881, 34882, 33825, 
33824, 33824, 34883, 33861, 33862, 33862, 33863, 33863, 33863, 34922, 34958, 
36017, 44435, 57078, 58103, 58135, 60216, 61307, 65535, 50751, 32799, 32799, 
57087, 65535, 50804, 61306, 62329, 61272, 60184, 59159, 59159, 60216, 58135, 
48723, 43473, 43440, 41326, 40301, 39211, 34948, 33824, 55989, 57046, 57078, 
58168, 58136, 43344, 34925, 34924, 34924, 34924, 34956, 35981, 34956, 33897, 
34887, 33863, 33863, 33862, 33829, 32803, 32769, 33792, 33824, 34848, 34881, 
33857, 33825, 33824, 34880, 33824, 34914, 39211, 41358, 42383, 42415, 43440, 
43472, 43472, 43473, 43440, 43440, 42383, 38120, 34848, 33824, 34914, 37095, 
39243, 40267, 40234, 38120, 35939, 33824, 35971, 35974, 33861, 33862, 33862, 
33863, 33863, 33865, 34957, 37040, 46548, 59159, 59159, 59159, 60248, 60216, 
65535, 65535, 65535, 65535, 65535, 62364, 50771, 60216, 59159, 59159, 58103, 
58103, 58135, 59159, 57046, 49747, 43472, 43441, 42383, 41358, 41326, 38153, 
33858, 54965, 57046, 58135, 58135, 58135, 42320, 33900, 34924, 34923, 34923, 
34924, 34923, 34887, 33862, 34887, 34886, 33829, 33861, 34916, 33825, 32768, 
34882, 37030, 39176, 40267, 40267, 39210, 38119, 35939, 34881, 33856, 38120, 
42415, 43472, 44529, 44529, 44529, 44529, 44530, 44529, 44529, 43440, 38054, 
34881, 38086, 42382, 43505, 42481, 44497, 43472, 43472, 41325, 36006, 37095, 
40268, 38121, 34918, 33861, 34887, 33864, 34923, 34957, 37039, 50741, 59159, 
59191, 60216, 61305, 58135, 57079, 63421, 65535, 65535, 59226, 44430, 53876, 
57046, 57046, 55989, 56021, 58134, 57078, 57046, 54932, 50770, 46544, 43473, 
43473, 42415, 42415, 43439, 40269, 54933, 56022, 57079, 58135, 59192, 43409, 
33899, 34923, 34922, 34922, 34923, 33864, 33861, 33862, 33829, 33828, 34884, 
34950, 37062, 35939, 34914, 39177, 41292, 41357, 41358, 42383, 42383, 41358, 
41325, 39111, 34881, 38086, 43440, 44529, 44530, 44562, 44562, 45586, 45587, 
46611, 45586, 43439, 37029, 37062, 43439, 45587, 45554, 44530, 45554, 45586, 
45553, 44497, 42382, 40301, 43439, 42382, 40236, 35975, 33861, 34920, 35948, 
34925, 39119, 52853, 58102, 58103, 58135, 57079, 53908, 51761, 52818, 50770, 
39145, 37098, 41293, 56022, 58103, 57078, 57078, 58134, 57078, 54965, 53908, 
51794, 50737, 48624, 44463, 43473, 43473, 43472, 43440, 42416, 54965, 57046, 
57079, 58135, 59192, 46545, 34923, 34922, 34921, 34921, 34889, 34886, 33829, 
33828, 33860, 35973, 37063, 38153, 38154, 38120, 39210, 41358, 42383, 43439, 
43440, 42416, 42383, 42383, 42416, 42415, 39177, 37029, 42382, 45554, 44562, 
45586, 45619, 45619, 47667, 47667, 46643, 44496, 40201, 44464, 46578, 45553, 
45585, 46577, 45521, 45554, 44563, 44530, 45587, 45586, 45554, 45554, 44496, 
39179, 32804, 33861, 34922, 34924, 42319, 52852, 53875, 53875, 52818, 52819, 
51794, 52819, 53843, 54965, 46543, 37098, 44463, 58135, 58135, 58103, 59159, 
58135, 53876, 51762, 51795, 51762, 50737, 50737, 49681, 44463, 43439, 43473, 
43472, 43439
};

BitTest4::BitTest4() : BitmapWrapper(bittest4_Bitmap, 92, 28) { };