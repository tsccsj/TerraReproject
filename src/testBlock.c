/**
 * testRepro.c
 * Authors: Yizhao Gao <ygao29@illinois.edu>
 * Date: {07/14/2017}
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "reproject.h"

int main(int argc, char ** argv) {

//In 10
	double inLat[100] = {
40.677159, 40.677153, 40.677148, 40.677142, 40.677137, 40.677131, 40.677126, 40.677121, 40.677115, 40.677110, 
40.676348, 40.676342, 40.676337, 40.676332, 40.676326, 40.676321, 40.676315, 40.676310, 40.676304, 40.676299, 
40.675537, 40.675532, 40.675526, 40.675521, 40.675515, 40.675510, 40.675504, 40.675499, 40.675494, 40.675488, 
40.674726, 40.674721, 40.674715, 40.674710, 40.674705, 40.674699, 40.674694, 40.674688, 40.674683, 40.674677, 
40.673916, 40.673910, 40.673905, 40.673899, 40.673894, 40.673888, 40.673883, 40.673877, 40.673872, 40.673867, 
40.673105, 40.673099, 40.673094, 40.673089, 40.673083, 40.673078, 40.673072, 40.673067, 40.673061, 40.673056, 
40.672294, 40.672289, 40.672283, 40.672278, 40.672272, 40.672267, 40.672261, 40.672256, 40.672251, 40.672245, 
40.671483, 40.671478, 40.671472, 40.671467, 40.671462, 40.671456, 40.671451, 40.671445, 40.671440, 40.671434, 
40.670673, 40.670667, 40.670662, 40.670656, 40.670651, 40.670645, 40.670640, 40.670634, 40.670629, 40.670624, 
40.669862, 40.669856, 40.669851, 40.669846, 40.669840, 40.669835, 40.669829, 40.669824, 40.669818, 40.669813
};
	double inLon[100] = {
-86.459595, -86.458530, -86.457466, -86.456401, -86.455336, -86.454271, -86.453206, -86.452141, -86.451076, -86.450011, 
-86.459602, -86.458537, -86.457472, -86.456407, -86.455342, -86.454277, -86.453213, -86.452148, -86.451083, -86.450018, 
-86.459608, -86.458544, -86.457479, -86.456414, -86.455349, -86.454284, -86.453219, -86.452154, -86.451089, -86.450025, 
-86.459615, -86.458550, -86.457485, -86.456420, -86.455356, -86.454291, -86.453226, -86.452161, -86.451096, -86.450031, 
-86.459621, -86.458557, -86.457492, -86.456427, -86.455362, -86.454297, -86.453232, -86.452168, -86.451103, -86.450038, 
-86.459628, -86.458563, -86.457498, -86.456434, -86.455369, -86.454304, -86.453239, -86.452174, -86.451109, -86.450045, 
-86.459635, -86.458570, -86.457505, -86.456440, -86.455375, -86.454310, -86.453246, -86.452181, -86.451116, -86.450051, 
-86.459641, -86.458576, -86.457511, -86.456447, -86.455382, -86.454317, -86.453252, -86.452187, -86.451123, -86.450058, 
-86.459648, -86.458583, -86.457518, -86.456453, -86.455388, -86.454324, -86.453259, -86.452194, -86.451129, -86.450064, 
-86.459654, -86.458589, -86.457525, -86.456460, -86.455395, -86.454330, -86.453265, -86.452201, -86.451136, -86.450071
};
	double inVal[100] = {
40.677159, 40.677153, 40.677148, 40.677142, 40.677137, 40.677131, 40.677126, 40.677121, 40.677115, 40.677110, 
40.676348, 40.676342, 40.676337, 40.676332, 40.676326, 40.676321, 40.676315, 40.676310, 40.676304, 40.676299, 
40.675537, 40.675532, 40.675526, 40.675521, 40.675515, 40.675510, 40.675504, 40.675499, 40.675494, 40.675488, 
40.674726, 40.674721, 40.674715, 40.674710, 40.674705, 40.674699, 40.674694, 40.674688, 40.674683, 40.674677, 
40.673916, 40.673910, 40.673905, 40.673899, 40.673894, 40.673888, 40.673883, 40.673877, 40.673872, 40.673867, 
40.673105, 40.673099, 40.673094, 40.673089, 40.673083, 40.673078, 40.673072, 40.673067, 40.673061, 40.673056, 
40.672294, 40.672289, 40.672283, 40.672278, 40.672272, 40.672267, 40.672261, 40.672256, 40.672251, 40.672245, 
40.671483, 40.671478, 40.671472, 40.671467, 40.671462, 40.671456, 40.671451, 40.671445, 40.671440, 40.671434, 
40.670673, 40.670667, 40.670662, 40.670656, 40.670651, 40.670645, 40.670640, 40.670634, 40.670629, 40.670624, 
40.669862, 40.669856, 40.669851, 40.669846, 40.669840, 40.669835, 40.669829, 40.669824, 40.669818, 40.669813
};

	int nIn = 100;


//In 20
/*	double inLat[400] = {
40.677159, 40.677153, 40.677148, 40.677142, 40.677137, 40.677131, 40.677126, 40.677121, 40.677115, 40.677110, 40.677104, 40.677099, 40.677093, 40.677088, 40.677082, 40.677077, 40.677071, 40.677066, 40.677061, 40.677055, 
40.676348, 40.676342, 40.676337, 40.676332, 40.676326, 40.676321, 40.676315, 40.676310, 40.676304, 40.676299, 40.676293, 40.676288, 40.676283, 40.676277, 40.676272, 40.676266, 40.676261, 40.676255, 40.676250, 40.676244, 
40.675537, 40.675532, 40.675526, 40.675521, 40.675515, 40.675510, 40.675504, 40.675499, 40.675494, 40.675488, 40.675483, 40.675477, 40.675472, 40.675466, 40.675461, 40.675455, 40.675450, 40.675445, 40.675439, 40.675434, 
40.674726, 40.674721, 40.674715, 40.674710, 40.674705, 40.674699, 40.674694, 40.674688, 40.674683, 40.674677, 40.674672, 40.674666, 40.674661, 40.674656, 40.674650, 40.674645, 40.674639, 40.674634, 40.674628, 40.674623, 
40.673916, 40.673910, 40.673905, 40.673899, 40.673894, 40.673888, 40.673883, 40.673877, 40.673872, 40.673867, 40.673861, 40.673856, 40.673850, 40.673845, 40.673839, 40.673834, 40.673828, 40.673823, 40.673818, 40.673812, 
40.673105, 40.673099, 40.673094, 40.673089, 40.673083, 40.673078, 40.673072, 40.673067, 40.673061, 40.673056, 40.673050, 40.673045, 40.673039, 40.673034, 40.673029, 40.673023, 40.673018, 40.673012, 40.673007, 40.673001, 
40.672294, 40.672289, 40.672283, 40.672278, 40.672272, 40.672267, 40.672261, 40.672256, 40.672251, 40.672245, 40.672240, 40.672234, 40.672229, 40.672223, 40.672218, 40.672212, 40.672207, 40.672201, 40.672196, 40.672191, 
40.671483, 40.671478, 40.671472, 40.671467, 40.671462, 40.671456, 40.671451, 40.671445, 40.671440, 40.671434, 40.671429, 40.671423, 40.671418, 40.671413, 40.671407, 40.671402, 40.671396, 40.671391, 40.671385, 40.671380, 
40.670673, 40.670667, 40.670662, 40.670656, 40.670651, 40.670645, 40.670640, 40.670634, 40.670629, 40.670624, 40.670618, 40.670613, 40.670607, 40.670602, 40.670596, 40.670591, 40.670585, 40.670580, 40.670575, 40.670569, 
40.669862, 40.669856, 40.669851, 40.669846, 40.669840, 40.669835, 40.669829, 40.669824, 40.669818, 40.669813, 40.669807, 40.669802, 40.669796, 40.669791, 40.669786, 40.669780, 40.669775, 40.669769, 40.669764, 40.669758, 
40.669051, 40.669046, 40.669040, 40.669035, 40.669029, 40.669024, 40.669018, 40.669013, 40.669008, 40.669002, 40.668997, 40.668991, 40.668986, 40.668980, 40.668975, 40.668969, 40.668964, 40.668958, 40.668953, 40.668948, 
40.668240, 40.668235, 40.668229, 40.668224, 40.668219, 40.668213, 40.668208, 40.668202, 40.668197, 40.668191, 40.668186, 40.668180, 40.668175, 40.668170, 40.668164, 40.668159, 40.668153, 40.668148, 40.668142, 40.668137, 
40.667430, 40.667424, 40.667419, 40.667413, 40.667408, 40.667402, 40.667397, 40.667391, 40.667386, 40.667381, 40.667375, 40.667370, 40.667364, 40.667359, 40.667353, 40.667348, 40.667342, 40.667337, 40.667332, 40.667326, 
40.666619, 40.666613, 40.666608, 40.666602, 40.666597, 40.666592, 40.666586, 40.666581, 40.666575, 40.666570, 40.666564, 40.666559, 40.666553, 40.666548, 40.666543, 40.666537, 40.666532, 40.666526, 40.666521, 40.666515, 
40.665808, 40.665803, 40.665797, 40.665792, 40.665786, 40.665781, 40.665775, 40.665770, 40.665764, 40.665759, 40.665754, 40.665748, 40.665743, 40.665737, 40.665732, 40.665726, 40.665721, 40.665715, 40.665710, 40.665705, 
40.664997, 40.664992, 40.664986, 40.664981, 40.664976, 40.664970, 40.664965, 40.664959, 40.664954, 40.664948, 40.664943, 40.664937, 40.664932, 40.664926, 40.664921, 40.664916, 40.664910, 40.664905, 40.664899, 40.664894, 
40.664187, 40.664181, 40.664176, 40.664170, 40.664165, 40.664159, 40.664154, 40.664148, 40.664143, 40.664138, 40.664132, 40.664127, 40.664121, 40.664116, 40.664110, 40.664105, 40.664099, 40.664094, 40.664089, 40.664083, 
40.663376, 40.663370, 40.663365, 40.663359, 40.663354, 40.663349, 40.663343, 40.663338, 40.663332, 40.663327, 40.663321, 40.663316, 40.663310, 40.663305, 40.663300, 40.663294, 40.663289, 40.663283, 40.663278, 40.663272, 
40.662565, 40.662560, 40.662554, 40.662549, 40.662543, 40.662538, 40.662532, 40.662527, 40.662521, 40.662516, 40.662511, 40.662505, 40.662500, 40.662494, 40.662489, 40.662483, 40.662478, 40.662472, 40.662467, 40.662462, 
40.661754, 40.661749, 40.661743, 40.661738, 40.661733, 40.661727, 40.661722, 40.661716, 40.661711, 40.661705, 40.661700, 40.661694, 40.661689, 40.661683, 40.661678, 40.661673, 40.661667, 40.661662, 40.661656, 40.661651
};
	double inLon[400] = {
-86.459595, -86.458530, -86.457466, -86.456401, -86.455336, -86.454271, -86.453206, -86.452141, -86.451076, -86.450011, -86.448946, -86.447881, -86.446817, -86.445752, -86.444687, -86.443622, -86.442557, -86.441492, -86.440427, -86.439362, 
-86.459602, -86.458537, -86.457472, -86.456407, -86.455342, -86.454277, -86.453213, -86.452148, -86.451083, -86.450018, -86.448953, -86.447888, -86.446823, -86.445758, -86.444694, -86.443629, -86.442564, -86.441499, -86.440434, -86.439369, 
-86.459608, -86.458544, -86.457479, -86.456414, -86.455349, -86.454284, -86.453219, -86.452154, -86.451089, -86.450025, -86.448960, -86.447895, -86.446830, -86.445765, -86.444700, -86.443635, -86.442570, -86.441506, -86.440441, -86.439376, 
-86.459615, -86.458550, -86.457485, -86.456420, -86.455356, -86.454291, -86.453226, -86.452161, -86.451096, -86.450031, -86.448966, -86.447902, -86.446837, -86.445772, -86.444707, -86.443642, -86.442577, -86.441512, -86.440448, -86.439383, 
-86.459621, -86.458557, -86.457492, -86.456427, -86.455362, -86.454297, -86.453232, -86.452168, -86.451103, -86.450038, -86.448973, -86.447908, -86.446843, -86.445779, -86.444714, -86.443649, -86.442584, -86.441519, -86.440454, -86.439389, 
-86.459628, -86.458563, -86.457498, -86.456434, -86.455369, -86.454304, -86.453239, -86.452174, -86.451109, -86.450045, -86.448980, -86.447915, -86.446850, -86.445785, -86.444720, -86.443656, -86.442591, -86.441526, -86.440461, -86.439396, 
-86.459635, -86.458570, -86.457505, -86.456440, -86.455375, -86.454310, -86.453246, -86.452181, -86.451116, -86.450051, -86.448986, -86.447922, -86.446857, -86.445792, -86.444727, -86.443662, -86.442597, -86.441533, -86.440468, -86.439403, 
-86.459641, -86.458576, -86.457511, -86.456447, -86.455382, -86.454317, -86.453252, -86.452187, -86.451123, -86.450058, -86.448993, -86.447928, -86.446863, -86.445799, -86.444734, -86.443669, -86.442604, -86.441539, -86.440475, -86.439410, 
-86.459648, -86.458583, -86.457518, -86.456453, -86.455388, -86.454324, -86.453259, -86.452194, -86.451129, -86.450064, -86.449000, -86.447935, -86.446870, -86.445805, -86.444741, -86.443676, -86.442611, -86.441546, -86.440481, -86.439417, 
-86.459654, -86.458589, -86.457525, -86.456460, -86.455395, -86.454330, -86.453265, -86.452201, -86.451136, -86.450071, -86.449006, -86.447942, -86.446877, -86.445812, -86.444747, -86.443682, -86.442618, -86.441553, -86.440488, -86.439423, 
-86.459661, -86.458596, -86.457531, -86.456466, -86.455402, -86.454337, -86.453272, -86.452207, -86.451143, -86.450078, -86.449013, -86.447948, -86.446883, -86.445819, -86.444754, -86.443689, -86.442624, -86.441560, -86.440495, -86.439430, 
-86.459667, -86.458602, -86.457538, -86.456473, -86.455408, -86.454343, -86.453279, -86.452214, -86.451149, -86.450084, -86.449020, -86.447955, -86.446890, -86.445825, -86.444761, -86.443696, -86.442631, -86.441566, -86.440502, -86.439437, 
-86.459674, -86.458609, -86.457544, -86.456480, -86.455415, -86.454350, -86.453285, -86.452221, -86.451156, -86.450091, -86.449026, -86.447962, -86.446897, -86.445832, -86.444767, -86.443703, -86.442638, -86.441573, -86.440508, -86.439444, 
-86.459680, -86.458616, -86.457551, -86.456486, -86.455421, -86.454357, -86.453292, -86.452227, -86.451162, -86.450098, -86.449033, -86.447968, -86.446904, -86.445839, -86.444774, -86.443709, -86.442645, -86.441580, -86.440515, -86.439450, 
-86.459687, -86.458622, -86.457557, -86.456493, -86.455428, -86.454363, -86.453299, -86.452234, -86.451169, -86.450104, -86.449040, -86.447975, -86.446910, -86.445846, -86.444781, -86.443716, -86.442651, -86.441587, -86.440522, -86.439457, 
-86.459693, -86.458629, -86.457564, -86.456499, -86.455435, -86.454370, -86.453305, -86.452240, -86.451176, -86.450111, -86.449046, -86.447982, -86.446917, -86.445852, -86.444788, -86.443723, -86.442658, -86.441593, -86.440529, -86.439464, 
-86.459700, -86.458635, -86.457571, -86.456506, -86.455441, -86.454376, -86.453312, -86.452247, -86.451182, -86.450118, -86.449053, -86.447988, -86.446924, -86.445859, -86.444794, -86.443730, -86.442665, -86.441600, -86.440536, -86.439471, 
-86.459706, -86.458642, -86.457577, -86.456512, -86.455448, -86.454383, -86.453318, -86.452254, -86.451189, -86.450124, -86.449060, -86.447995, -86.446930, -86.445866, -86.444801, -86.443736, -86.442672, -86.441607, -86.440542, -86.439478, 
-86.459713, -86.458648, -86.457584, -86.456519, -86.455454, -86.454390, -86.453325, -86.452260, -86.451196, -86.450131, -86.449066, -86.448002, -86.446937, -86.445872, -86.444808, -86.443743, -86.442678, -86.441614, -86.440549, -86.439484, 
-86.459720, -86.458655, -86.457590, -86.456526, -86.455461, -86.454396, -86.453332, -86.452267, -86.451202, -86.450138, -86.449073, -86.448008, -86.446944, -86.445879, -86.444814, -86.443750, -86.442685, -86.441620, -86.440556, -86.439491
};
	double inVal[400] = {
40.677159, 40.677153, 40.677148, 40.677142, 40.677137, 40.677131, 40.677126, 40.677121, 40.677115, 40.677110, 40.677104, 40.677099, 40.677093, 40.677088, 40.677082, 40.677077, 40.677071, 40.677066, 40.677061, 40.677055, 
40.676348, 40.676342, 40.676337, 40.676332, 40.676326, 40.676321, 40.676315, 40.676310, 40.676304, 40.676299, 40.676293, 40.676288, 40.676283, 40.676277, 40.676272, 40.676266, 40.676261, 40.676255, 40.676250, 40.676244, 
40.675537, 40.675532, 40.675526, 40.675521, 40.675515, 40.675510, 40.675504, 40.675499, 40.675494, 40.675488, 40.675483, 40.675477, 40.675472, 40.675466, 40.675461, 40.675455, 40.675450, 40.675445, 40.675439, 40.675434, 
40.674726, 40.674721, 40.674715, 40.674710, 40.674705, 40.674699, 40.674694, 40.674688, 40.674683, 40.674677, 40.674672, 40.674666, 40.674661, 40.674656, 40.674650, 40.674645, 40.674639, 40.674634, 40.674628, 40.674623, 
40.673916, 40.673910, 40.673905, 40.673899, 40.673894, 40.673888, 40.673883, 40.673877, 40.673872, 40.673867, 40.673861, 40.673856, 40.673850, 40.673845, 40.673839, 40.673834, 40.673828, 40.673823, 40.673818, 40.673812, 
40.673105, 40.673099, 40.673094, 40.673089, 40.673083, 40.673078, 40.673072, 40.673067, 40.673061, 40.673056, 40.673050, 40.673045, 40.673039, 40.673034, 40.673029, 40.673023, 40.673018, 40.673012, 40.673007, 40.673001, 
40.672294, 40.672289, 40.672283, 40.672278, 40.672272, 40.672267, 40.672261, 40.672256, 40.672251, 40.672245, 40.672240, 40.672234, 40.672229, 40.672223, 40.672218, 40.672212, 40.672207, 40.672201, 40.672196, 40.672191, 
40.671483, 40.671478, 40.671472, 40.671467, 40.671462, 40.671456, 40.671451, 40.671445, 40.671440, 40.671434, 40.671429, 40.671423, 40.671418, 40.671413, 40.671407, 40.671402, 40.671396, 40.671391, 40.671385, 40.671380, 
40.670673, 40.670667, 40.670662, 40.670656, 40.670651, 40.670645, 40.670640, 40.670634, 40.670629, 40.670624, 40.670618, 40.670613, 40.670607, 40.670602, 40.670596, 40.670591, 40.670585, 40.670580, 40.670575, 40.670569, 
40.669862, 40.669856, 40.669851, 40.669846, 40.669840, 40.669835, 40.669829, 40.669824, 40.669818, 40.669813, 40.669807, 40.669802, 40.669796, 40.669791, 40.669786, 40.669780, 40.669775, 40.669769, 40.669764, 40.669758, 
40.669051, 40.669046, 40.669040, 40.669035, 40.669029, 40.669024, 40.669018, 40.669013, 40.669008, 40.669002, 40.668997, 40.668991, 40.668986, 40.668980, 40.668975, 40.668969, 40.668964, 40.668958, 40.668953, 40.668948, 
40.668240, 40.668235, 40.668229, 40.668224, 40.668219, 40.668213, 40.668208, 40.668202, 40.668197, 40.668191, 40.668186, 40.668180, 40.668175, 40.668170, 40.668164, 40.668159, 40.668153, 40.668148, 40.668142, 40.668137, 
40.667430, 40.667424, 40.667419, 40.667413, 40.667408, 40.667402, 40.667397, 40.667391, 40.667386, 40.667381, 40.667375, 40.667370, 40.667364, 40.667359, 40.667353, 40.667348, 40.667342, 40.667337, 40.667332, 40.667326, 
40.666619, 40.666613, 40.666608, 40.666602, 40.666597, 40.666592, 40.666586, 40.666581, 40.666575, 40.666570, 40.666564, 40.666559, 40.666553, 40.666548, 40.666543, 40.666537, 40.666532, 40.666526, 40.666521, 40.666515, 
40.665808, 40.665803, 40.665797, 40.665792, 40.665786, 40.665781, 40.665775, 40.665770, 40.665764, 40.665759, 40.665754, 40.665748, 40.665743, 40.665737, 40.665732, 40.665726, 40.665721, 40.665715, 40.665710, 40.665705, 
40.664997, 40.664992, 40.664986, 40.664981, 40.664976, 40.664970, 40.664965, 40.664959, 40.664954, 40.664948, 40.664943, 40.664937, 40.664932, 40.664926, 40.664921, 40.664916, 40.664910, 40.664905, 40.664899, 40.664894, 
40.664187, 40.664181, 40.664176, 40.664170, 40.664165, 40.664159, 40.664154, 40.664148, 40.664143, 40.664138, 40.664132, 40.664127, 40.664121, 40.664116, 40.664110, 40.664105, 40.664099, 40.664094, 40.664089, 40.664083, 
40.663376, 40.663370, 40.663365, 40.663359, 40.663354, 40.663349, 40.663343, 40.663338, 40.663332, 40.663327, 40.663321, 40.663316, 40.663310, 40.663305, 40.663300, 40.663294, 40.663289, 40.663283, 40.663278, 40.663272, 
40.662565, 40.662560, 40.662554, 40.662549, 40.662543, 40.662538, 40.662532, 40.662527, 40.662521, 40.662516, 40.662511, 40.662505, 40.662500, 40.662494, 40.662489, 40.662483, 40.662478, 40.662472, 40.662467, 40.662462, 
40.661754, 40.661749, 40.661743, 40.661738, 40.661733, 40.661727, 40.661722, 40.661716, 40.661711, 40.661705, 40.661700, 40.661694, 40.661689, 40.661683, 40.661678, 40.661673, 40.661667, 40.661662, 40.661656, 40.661651
};

	int nIn = 400;
*/

//Out 10

	double outLat[100] = {
40.677159, 40.677154, 40.677149, 40.677144, 40.677139, 40.677134, 40.677129, 40.677124, 40.677118, 40.677113, 
40.676348, 40.676343, 40.676338, 40.676333, 40.676328, 40.676323, 40.676318, 40.676313, 40.676308, 40.676303, 
40.675537, 40.675532, 40.675527, 40.675522, 40.675517, 40.675512, 40.675507, 40.675502, 40.675497, 40.675492, 
40.674726, 40.674721, 40.674716, 40.674711, 40.674706, 40.674701, 40.674696, 40.674691, 40.674686, 40.674681, 
40.673916, 40.673911, 40.673906, 40.673901, 40.673896, 40.673891, 40.673886, 40.673880, 40.673875, 40.673870, 
40.673105, 40.673100, 40.673095, 40.673090, 40.673085, 40.673080, 40.673075, 40.673070, 40.673065, 40.673060, 
40.672294, 40.672289, 40.672284, 40.672279, 40.672274, 40.672269, 40.672264, 40.672259, 40.672254, 40.672249, 
40.671483, 40.671478, 40.671473, 40.671468, 40.671463, 40.671458, 40.671453, 40.671448, 40.671443, 40.671438, 
40.670673, 40.670668, 40.670663, 40.670658, 40.670653, 40.670648, 40.670643, 40.670637, 40.670632, 40.670627, 
40.669862, 40.669857, 40.669852, 40.669847, 40.669842, 40.669837, 40.669832, 40.669827, 40.669822, 40.669817
};

	double outLon[100] = {
-86.459595, -86.458530, -86.457466, -86.456401, -86.455336, -86.454271, -86.453206, -86.452141, -86.451076, -86.450011, 
-86.459602, -86.458537, -86.457472, -86.456407, -86.455342, -86.454277, -86.453213, -86.452148, -86.451083, -86.450018, 
-86.459608, -86.458544, -86.457479, -86.456414, -86.455349, -86.454284, -86.453219, -86.452154, -86.451089, -86.450025, 
-86.459615, -86.458550, -86.457485, -86.456420, -86.455356, -86.454291, -86.453226, -86.452161, -86.451096, -86.450031, 
-86.459621, -86.458557, -86.457492, -86.456427, -86.455362, -86.454297, -86.453232, -86.452168, -86.451103, -86.450038, 
-86.459628, -86.458563, -86.457498, -86.456434, -86.455369, -86.454304, -86.453239, -86.452174, -86.451109, -86.450045, 
-86.459635, -86.458570, -86.457505, -86.456440, -86.455375, -86.454310, -86.453246, -86.452181, -86.451116, -86.450051, 
-86.459641, -86.458576, -86.457511, -86.456447, -86.455382, -86.454317, -86.453252, -86.452187, -86.451123, -86.450058, 
-86.459648, -86.458583, -86.457518, -86.456453, -86.455388, -86.454324, -86.453259, -86.452194, -86.451129, -86.450064, 
-86.459654, -86.458589, -86.457525, -86.456460, -86.455395, -86.454330, -86.453265, -86.452201, -86.451136, -86.450071
};


	int nOut = 100;

//Out 20
/*	double outLat[400] = {
40.677159, 40.677154, 40.677149, 40.677144, 40.677139, 40.677134, 40.677129, 40.677124, 40.677118, 40.677113, 40.677108, 40.677103, 40.677098, 40.677093, 40.677088, 40.677083, 40.677078, 40.677072, 40.677067, 40.677062, 
40.676348, 40.676343, 40.676338, 40.676333, 40.676328, 40.676323, 40.676318, 40.676313, 40.676308, 40.676303, 40.676298, 40.676292, 40.676287, 40.676282, 40.676277, 40.676272, 40.676267, 40.676262, 40.676257, 40.676251, 
40.675537, 40.675532, 40.675527, 40.675522, 40.675517, 40.675512, 40.675507, 40.675502, 40.675497, 40.675492, 40.675487, 40.675482, 40.675477, 40.675472, 40.675466, 40.675461, 40.675456, 40.675451, 40.675446, 40.675441, 
40.674726, 40.674721, 40.674716, 40.674711, 40.674706, 40.674701, 40.674696, 40.674691, 40.674686, 40.674681, 40.674676, 40.674671, 40.674666, 40.674661, 40.674656, 40.674651, 40.674645, 40.674640, 40.674635, 40.674630, 
40.673916, 40.673911, 40.673906, 40.673901, 40.673896, 40.673891, 40.673886, 40.673880, 40.673875, 40.673870, 40.673865, 40.673860, 40.673855, 40.673850, 40.673845, 40.673840, 40.673835, 40.673829, 40.673824, 40.673819, 
40.673105, 40.673100, 40.673095, 40.673090, 40.673085, 40.673080, 40.673075, 40.673070, 40.673065, 40.673060, 40.673055, 40.673049, 40.673044, 40.673039, 40.673034, 40.673029, 40.673024, 40.673019, 40.673014, 40.673008, 
40.672294, 40.672289, 40.672284, 40.672279, 40.672274, 40.672269, 40.672264, 40.672259, 40.672254, 40.672249, 40.672244, 40.672239, 40.672234, 40.672228, 40.672223, 40.672218, 40.672213, 40.672208, 40.672203, 40.672198, 
40.671483, 40.671478, 40.671473, 40.671468, 40.671463, 40.671458, 40.671453, 40.671448, 40.671443, 40.671438, 40.671433, 40.671428, 40.671423, 40.671418, 40.671413, 40.671407, 40.671402, 40.671397, 40.671392, 40.671387, 
40.670673, 40.670668, 40.670663, 40.670658, 40.670653, 40.670648, 40.670643, 40.670637, 40.670632, 40.670627, 40.670622, 40.670617, 40.670612, 40.670607, 40.670602, 40.670597, 40.670592, 40.670586, 40.670581, 40.670576, 
40.669862, 40.669857, 40.669852, 40.669847, 40.669842, 40.669837, 40.669832, 40.669827, 40.669822, 40.669817, 40.669812, 40.669806, 40.669801, 40.669796, 40.669791, 40.669786, 40.669781, 40.669776, 40.669771, 40.669765, 
40.669051, 40.669046, 40.669041, 40.669036, 40.669031, 40.669026, 40.669021, 40.669016, 40.669011, 40.669006, 40.669001, 40.668996, 40.668991, 40.668985, 40.668980, 40.668975, 40.668970, 40.668965, 40.668960, 40.668955, 
40.668240, 40.668235, 40.668230, 40.668225, 40.668220, 40.668215, 40.668210, 40.668205, 40.668200, 40.668195, 40.668190, 40.668185, 40.668180, 40.668175, 40.668170, 40.668164, 40.668159, 40.668154, 40.668149, 40.668144, 
40.667430, 40.667425, 40.667420, 40.667415, 40.667410, 40.667405, 40.667400, 40.667394, 40.667389, 40.667384, 40.667379, 40.667374, 40.667369, 40.667364, 40.667359, 40.667354, 40.667349, 40.667343, 40.667338, 40.667333, 
40.666619, 40.666614, 40.666609, 40.666604, 40.666599, 40.666594, 40.666589, 40.666584, 40.666579, 40.666574, 40.666568, 40.666563, 40.666558, 40.666553, 40.666548, 40.666543, 40.666538, 40.666533, 40.666528, 40.666522, 
40.665808, 40.665803, 40.665798, 40.665793, 40.665788, 40.665783, 40.665778, 40.665773, 40.665768, 40.665763, 40.665758, 40.665753, 40.665748, 40.665742, 40.665737, 40.665732, 40.665727, 40.665722, 40.665717, 40.665712, 
40.664997, 40.664992, 40.664987, 40.664982, 40.664977, 40.664972, 40.664967, 40.664962, 40.664957, 40.664952, 40.664947, 40.664942, 40.664937, 40.664932, 40.664927, 40.664921, 40.664916, 40.664911, 40.664906, 40.664901, 
40.664187, 40.664182, 40.664177, 40.664172, 40.664167, 40.664162, 40.664156, 40.664151, 40.664146, 40.664141, 40.664136, 40.664131, 40.664126, 40.664121, 40.664116, 40.664111, 40.664106, 40.664100, 40.664095, 40.664090, 
40.663376, 40.663371, 40.663366, 40.663361, 40.663356, 40.663351, 40.663346, 40.663341, 40.663336, 40.663331, 40.663325, 40.663320, 40.663315, 40.663310, 40.663305, 40.663300, 40.663295, 40.663290, 40.663285, 40.663279, 
40.662565, 40.662560, 40.662555, 40.662550, 40.662545, 40.662540, 40.662535, 40.662530, 40.662525, 40.662520, 40.662515, 40.662510, 40.662505, 40.662499, 40.662494, 40.662489, 40.662484, 40.662479, 40.662474, 40.662469, 
40.661754, 40.661749, 40.661744, 40.661739, 40.661734, 40.661729, 40.661724, 40.661719, 40.661714, 40.661709, 40.661704, 40.661699, 40.661694, 40.661689, 40.661684, 40.661678, 40.661673, 40.661668, 40.661663, 40.661658
};
	double outLon[400] = {
-86.459595, -86.458530, -86.457466, -86.456401, -86.455336, -86.454271, -86.453206, -86.452141, -86.451076, -86.450011, -86.448946, -86.447881, -86.446817, -86.445752, -86.444687, -86.443622, -86.442557, -86.441492, -86.440427, -86.439362, 
-86.459602, -86.458537, -86.457472, -86.456407, -86.455342, -86.454277, -86.453213, -86.452148, -86.451083, -86.450018, -86.448953, -86.447888, -86.446823, -86.445758, -86.444693, -86.443629, -86.442564, -86.441499, -86.440434, -86.439369, 
-86.459608, -86.458544, -86.457479, -86.456414, -86.455349, -86.454284, -86.453219, -86.452154, -86.451089, -86.450025, -86.448960, -86.447895, -86.446830, -86.445765, -86.444700, -86.443635, -86.442570, -86.441506, -86.440441, -86.439376, 
-86.459615, -86.458550, -86.457485, -86.456420, -86.455356, -86.454291, -86.453226, -86.452161, -86.451096, -86.450031, -86.448966, -86.447901, -86.446837, -86.445772, -86.444707, -86.443642, -86.442577, -86.441512, -86.440447, -86.439383, 
-86.459621, -86.458557, -86.457492, -86.456427, -86.455362, -86.454297, -86.453232, -86.452168, -86.451103, -86.450038, -86.448973, -86.447908, -86.446843, -86.445778, -86.444714, -86.443649, -86.442584, -86.441519, -86.440454, -86.439389, 
-86.459628, -86.458563, -86.457498, -86.456434, -86.455369, -86.454304, -86.453239, -86.452174, -86.451109, -86.450045, -86.448980, -86.447915, -86.446850, -86.445785, -86.444720, -86.443655, -86.442591, -86.441526, -86.440461, -86.439396, 
-86.459635, -86.458570, -86.457505, -86.456440, -86.455375, -86.454310, -86.453246, -86.452181, -86.451116, -86.450051, -86.448986, -86.447922, -86.446857, -86.445792, -86.444727, -86.443662, -86.442597, -86.441533, -86.440468, -86.439403, 
-86.459641, -86.458576, -86.457511, -86.456447, -86.455382, -86.454317, -86.453252, -86.452187, -86.451123, -86.450058, -86.448993, -86.447928, -86.446863, -86.445799, -86.444734, -86.443669, -86.442604, -86.441539, -86.440475, -86.439410, 
-86.459648, -86.458583, -86.457518, -86.456453, -86.455388, -86.454324, -86.453259, -86.452194, -86.451129, -86.450064, -86.449000, -86.447935, -86.446870, -86.445805, -86.444740, -86.443676, -86.442611, -86.441546, -86.440481, -86.439416, 
-86.459654, -86.458589, -86.457525, -86.456460, -86.455395, -86.454330, -86.453265, -86.452201, -86.451136, -86.450071, -86.449006, -86.447942, -86.446877, -86.445812, -86.444747, -86.443682, -86.442618, -86.441553, -86.440488, -86.439423, 
-86.459661, -86.458596, -86.457531, -86.456466, -86.455402, -86.454337, -86.453272, -86.452207, -86.451143, -86.450078, -86.449013, -86.447948, -86.446883, -86.445819, -86.444754, -86.443689, -86.442624, -86.441560, -86.440495, -86.439430, 
-86.459667, -86.458603, -86.457538, -86.456473, -86.455408, -86.454343, -86.453279, -86.452214, -86.451149, -86.450084, -86.449020, -86.447955, -86.446890, -86.445825, -86.444761, -86.443696, -86.442631, -86.441566, -86.440502, -86.439437, 
-86.459674, -86.458609, -86.457544, -86.456480, -86.455415, -86.454350, -86.453285, -86.452221, -86.451156, -86.450091, -86.449026, -86.447962, -86.446897, -86.445832, -86.444767, -86.443703, -86.442638, -86.441573, -86.440508, -86.439444, 
-86.459680, -86.458616, -86.457551, -86.456486, -86.455421, -86.454357, -86.453292, -86.452227, -86.451162, -86.450098, -86.449033, -86.447968, -86.446904, -86.445839, -86.444774, -86.443709, -86.442645, -86.441580, -86.440515, -86.439450, 
-86.459687, -86.458622, -86.457557, -86.456493, -86.455428, -86.454363, -86.453299, -86.452234, -86.451169, -86.450104, -86.449040, -86.447975, -86.446910, -86.445846, -86.444781, -86.443716, -86.442651, -86.441587, -86.440522, -86.439457, 
-86.459693, -86.458629, -86.457564, -86.456499, -86.455435, -86.454370, -86.453305, -86.452240, -86.451176, -86.450111, -86.449046, -86.447982, -86.446917, -86.445852, -86.444788, -86.443723, -86.442658, -86.441593, -86.440529, -86.439464, 
-86.459700, -86.458635, -86.457571, -86.456506, -86.455441, -86.454377, -86.453312, -86.452247, -86.451182, -86.450118, -86.449053, -86.447988, -86.446924, -86.445859, -86.444794, -86.443730, -86.442665, -86.441600, -86.440535, -86.439471, 
-86.459707, -86.458642, -86.457577, -86.456512, -86.455448, -86.454383, -86.453318, -86.452254, -86.451189, -86.450124, -86.449060, -86.447995, -86.446930, -86.445866, -86.444801, -86.443736, -86.442672, -86.441607, -86.440542, -86.439478, 
-86.459713, -86.458648, -86.457584, -86.456519, -86.455454, -86.454390, -86.453325, -86.452260, -86.451196, -86.450131, -86.449066, -86.448002, -86.446937, -86.445872, -86.444808, -86.443743, -86.442678, -86.441614, -86.440549, -86.439484, 
-86.459720, -86.458655, -86.457590, -86.456526, -86.455461, -86.454396, -86.453332, -86.452267, -86.451202, -86.450138, -86.449073, -86.448008, -86.446944, -86.445879, -86.444814, -86.443750, -86.442685, -86.441620, -86.440556, -86.439491
};
	double outVal[400];

	int nOut = 400;
*/
	double maxR = 100;
/*
	double latMax = 40.677113; 
	double latMin = 40.669862;
	double lonMax = -86.450011;
	double lonMin = -86.459654;
*/


	double *iLat, *iLon, *oLat, *oLon, *iVal, *oVal;
	double **piLat, **piLon;
	int *tarNNSouID;
	iLat=(double *)malloc(sizeof(double) * nIn);
	iLon=(double *)malloc(sizeof(double) * nIn);
	iVal=(double *)malloc(sizeof(double) * nIn);

	piLat = &iLat;
	piLon = &iLon;


	oLat=(double *)malloc(sizeof(double) * nOut);
	oLon=(double *)malloc(sizeof(double) * nOut);
	oVal=(double *)malloc(sizeof(double) * nOut);
	tarNNSouID=(int *)malloc(sizeof(int) * nOut);


	for(int i = 0; i < nIn; i++) {
		iLat[i] = inLat[i];
		iLon[i] = inLon[i];
		iVal[i] = inVal[i];
	}

	for(int i = 0; i < nOut; i++) {
		oLat[i] = outLat[i];
		oLon[i] = outLon[i];
	}


	double * tarNNDis;
	tarNNDis=(double *)malloc(sizeof(double) * nOut);


//	nearestNeighbor(piLat, piLon, nIn, oLat, oLon, tarNNSouID, nOut, maxR);
//	nearestNeighbor(piLat, piLon, nIn, oLat, oLon, tarNNSouID, tarNNDis, nOut, maxR);
	nearestNeighbor(piLat, piLon, nIn, oLat, oLon, tarNNSouID, tarNNDis, nOut, 2000000);
//	testBlockIndex(piLat, piLon, nIn, oLat, oLon, tarNNSouID, tarNNDis, nOut, 2000000);

//	nnInterpolate(iVal, oVal, tarNNSouID, nOut);

//	interpolateNN(inLat, inLon, inVal, nIn, outLat, outLon, outVal, nOut, maxR);
/*
	printf("InLat, InLon\n");
	for(int i = 0; i < nIn; i++) {
		printf("%lf,%lf\n", inLat[i], inLon[i]);
	}

	printf("OutLat, OutLon, Val\n");
	for(int i = 0; i < nOut; i++) {
		printf("%lf,\t%lf,\t%lf,\t%lf\n", outLat[i], outLon[i], oVal[i], tarNNDis[i]);
//		printf("%lf,%lf,%d\n", outLat[i], outLon[i], tarNNSouID[i]);
	}
*/
	free(*piLat);
	free(*piLon);
	free(iVal);
	free(oLat);
	free(oLon);
	free(oVal);
	free(tarNNSouID);
	
	return 0;
}
