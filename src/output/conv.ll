; ModuleID = 'llvm-link'
source_filename = "llvm-link"
target datalayout = "e-m:o-i64:64-i128:128-n32:64-S128"
target triple = "arm64-apple-macosx15.0.0"

%struct.timeval = type { i64, i32 }

@max = global i32 1073741824
@a = global [10000000 x i32] zeroinitializer
@b = global [10000000 x i32] zeroinitializer
@kernelid_ = global [10000 x i32] zeroinitializer
@llvm.global_ctors = appending global [2 x { i32, ptr, ptr }] [{ i32, ptr, ptr } { i32 65535, ptr @before_main, ptr null }, { i32, ptr, ptr } { i32 65535, ptr @__GLOBAL_init_65535, ptr null }]
@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
@.str.1 = private unnamed_addr constant [3 x i8] c"%c\00", align 1
@.str.2 = private unnamed_addr constant [4 x i8] c"%d:\00", align 1
@.str.3 = private unnamed_addr constant [4 x i8] c" %d\00", align 1
@.str.4 = private unnamed_addr constant [2 x i8] c"\0A\00", align 1
@_sysy_us = global [1024 x i32] zeroinitializer, align 4
@_sysy_s = global [1024 x i32] zeroinitializer, align 4
@_sysy_m = global [1024 x i32] zeroinitializer, align 4
@_sysy_h = global [1024 x i32] zeroinitializer, align 4
@_sysy_idx = global i32 0, align 4
@__stderrp = external global ptr, align 8
@.str.5 = private unnamed_addr constant [35 x i8] c"Timer@%04d-%04d: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_l1 = global [1024 x i32] zeroinitializer, align 4
@_sysy_l2 = global [1024 x i32] zeroinitializer, align 4
@.str.6 = private unnamed_addr constant [25 x i8] c"TOTAL: %dH-%dM-%dS-%dus\0A\00", align 1
@_sysy_start = global %struct.timeval zeroinitializer, align 8
@_sysy_end = global %struct.timeval zeroinitializer, align 8
@__dso_handle = external hidden global i8

define i32 @checkrange(i32 %r100) {
bb1:
  %r101 = alloca i32, align 4
  store i32 %r100, ptr %r101, align 4
  br label %bb2

bb2:                                              ; preds = %bb3, %bb1
  %r102 = load i32, ptr %r101, align 4
  %r103 = load i32, ptr @max, align 4
  %r104 = icmp sgt i32 %r102, %r103
  br i1 %r104, label %bb3, label %bb4

bb3:                                              ; preds = %bb2
  %r105 = load i32, ptr %r101, align 4
  %r106 = load i32, ptr @max, align 4
  %r107 = sub i32 %r105, %r106
  store i32 %r107, ptr %r101, align 4
  br label %bb2

bb4:                                              ; preds = %bb2
  br label %bb5

bb5:                                              ; preds = %bb6, %bb4
  %r108 = load i32, ptr %r101, align 4
  %r109 = icmp slt i32 %r108, 0
  br i1 %r109, label %bb6, label %bb7

bb6:                                              ; preds = %bb5
  %r110 = load i32, ptr %r101, align 4
  %r111 = load i32, ptr @max, align 4
  %r112 = add i32 %r110, %r111
  store i32 %r112, ptr %r101, align 4
  br label %bb5

bb7:                                              ; preds = %bb5
  %r113 = load i32, ptr %r101, align 4
  ret i32 %r113
}

define i32 @mod(i32 %r114, i32 %r116) {
bb8:
  %r115 = alloca i32, align 4
  store i32 %r114, ptr %r115, align 4
  %r117 = alloca i32, align 4
  store i32 %r116, ptr %r117, align 4
  %r118 = load i32, ptr %r115, align 4
  %r119 = load i32, ptr %r115, align 4
  %r120 = load i32, ptr %r117, align 4
  %r121 = sdiv i32 %r119, %r120
  %r122 = load i32, ptr %r117, align 4
  %r123 = mul i32 %r121, %r122
  %r124 = sub i32 %r118, %r123
  ret i32 %r124
}

define i32 @reduce(i32 %r125, i32 %r127, i32 %r129) {
bb9:
  %r196 = alloca i32, align 4
  %r195 = alloca i32, align 4
  %r171 = alloca i32, align 4
  %r170 = alloca i32, align 4
  %r140 = alloca i32, align 4
  %r139 = alloca i32, align 4
  %r126 = alloca i32, align 4
  store i32 %r125, ptr %r126, align 4
  %r128 = alloca i32, align 4
  store i32 %r127, ptr %r128, align 4
  %r130 = alloca i32, align 4
  store i32 %r129, ptr %r130, align 4
  %r131 = load i32, ptr %r126, align 4
  %r132 = icmp eq i32 %r131, 0
  br i1 %r132, label %bb10, label %bb11

bb10:                                             ; preds = %bb9
  %r133 = load i32, ptr %r128, align 4
  %r134 = load i32, ptr %r130, align 4
  %r135 = add i32 %r133, %r134
  %r136 = call i32 @checkrange(i32 %r135)
  ret i32 %r136

0:                                                ; No predecessors!
  br label %bb11

bb11:                                             ; preds = %0, %bb9
  %r137 = load i32, ptr %r126, align 4
  %r138 = icmp eq i32 %r137, 1
  br i1 %r138, label %bb12, label %bb13

bb12:                                             ; preds = %bb11
  store i32 0, ptr %r139, align 4
  store i32 1, ptr %r140, align 4
  br label %bb14

bb14:                                             ; preds = %bb19, %bb12
  %r141 = load i32, ptr %r140, align 4
  %r142 = load i32, ptr @max, align 4
  %r143 = icmp slt i32 %r141, %r142
  br i1 %r143, label %bb15, label %bb16

bb15:                                             ; preds = %bb14
  %r144 = load i32, ptr %r128, align 4
  %r145 = load i32, ptr %r140, align 4
  %r146 = sdiv i32 %r144, %r145
  %r147 = call i32 @mod(i32 %r146, i32 2)
  %r148 = load i32, ptr %r130, align 4
  %r149 = load i32, ptr %r140, align 4
  %r150 = sdiv i32 %r148, %r149
  %r151 = call i32 @mod(i32 %r150, i32 2)
  %r152 = icmp eq i32 %r147, %r151
  br i1 %r152, label %bb17, label %bb18

bb17:                                             ; preds = %bb15
  %r153 = load i32, ptr %r139, align 4
  %r154 = mul i32 %r153, 2
  store i32 %r154, ptr %r139, align 4
  br label %bb19

bb18:                                             ; preds = %bb15
  %r155 = load i32, ptr %r139, align 4
  %r156 = mul i32 %r155, 2
  %r157 = add i32 %r156, 1
  store i32 %r157, ptr %r139, align 4
  br label %bb19

bb19:                                             ; preds = %bb18, %bb17
  %r158 = load i32, ptr %r140, align 4
  %r159 = mul i32 %r158, 2
  store i32 %r159, ptr %r140, align 4
  br label %bb14

bb16:                                             ; preds = %bb14
  %r160 = load i32, ptr %r139, align 4
  ret i32 %r160

1:                                                ; No predecessors!
  br label %bb13

bb13:                                             ; preds = %1, %bb11
  %r161 = load i32, ptr %r126, align 4
  %r162 = icmp eq i32 %r161, 2
  br i1 %r162, label %bb20, label %bb21

bb20:                                             ; preds = %bb13
  %r163 = load i32, ptr %r128, align 4
  %r164 = load i32, ptr %r130, align 4
  %r165 = icmp sgt i32 %r163, %r164
  br i1 %r165, label %bb22, label %bb23

bb22:                                             ; preds = %bb20
  %r166 = load i32, ptr %r128, align 4
  ret i32 %r166

2:                                                ; No predecessors!
  br label %bb24

bb23:                                             ; preds = %bb20
  %r167 = load i32, ptr %r130, align 4
  ret i32 %r167

3:                                                ; No predecessors!
  br label %bb24

bb24:                                             ; preds = %3, %2
  br label %bb21

bb21:                                             ; preds = %bb24, %bb13
  %r168 = load i32, ptr %r126, align 4
  %r169 = icmp eq i32 %r168, 3
  br i1 %r169, label %bb25, label %bb26

bb25:                                             ; preds = %bb21
  store i32 0, ptr %r170, align 4
  store i32 1, ptr %r171, align 4
  br label %bb27

bb27:                                             ; preds = %bb32, %bb25
  %r172 = load i32, ptr %r171, align 4
  %r173 = load i32, ptr @max, align 4
  %r174 = icmp slt i32 %r172, %r173
  br i1 %r174, label %bb28, label %bb29

bb28:                                             ; preds = %bb27
  %r175 = load i32, ptr %r128, align 4
  %r176 = load i32, ptr %r171, align 4
  %r177 = sdiv i32 %r175, %r176
  %r178 = call i32 @mod(i32 %r177, i32 2)
  %r179 = icmp eq i32 %r178, 1
  br i1 %r179, label %bb30, label %bb33

bb33:                                             ; preds = %bb28
  %r180 = load i32, ptr %r130, align 4
  %r181 = load i32, ptr %r171, align 4
  %r182 = sdiv i32 %r180, %r181
  %r183 = call i32 @mod(i32 %r182, i32 2)
  %r184 = icmp eq i32 %r183, 1
  br i1 %r184, label %bb30, label %bb31

bb30:                                             ; preds = %bb33, %bb28
  %r185 = load i32, ptr %r170, align 4
  %r186 = mul i32 %r185, 2
  %r187 = add i32 %r186, 1
  store i32 %r187, ptr %r170, align 4
  br label %bb32

bb31:                                             ; preds = %bb33
  %r188 = load i32, ptr %r170, align 4
  %r189 = mul i32 %r188, 2
  store i32 %r189, ptr %r170, align 4
  br label %bb32

bb32:                                             ; preds = %bb31, %bb30
  %r190 = load i32, ptr %r171, align 4
  %r191 = mul i32 %r190, 2
  store i32 %r191, ptr %r171, align 4
  br label %bb27

bb29:                                             ; preds = %bb27
  %r192 = load i32, ptr %r170, align 4
  ret i32 %r192

4:                                                ; No predecessors!
  br label %bb26

bb26:                                             ; preds = %4, %bb21
  %r193 = load i32, ptr %r126, align 4
  %r194 = icmp eq i32 %r193, 4
  br i1 %r194, label %bb34, label %bb35

bb34:                                             ; preds = %bb26
  store i32 0, ptr %r195, align 4
  store i32 1, ptr %r196, align 4
  br label %bb36

bb36:                                             ; preds = %bb41, %bb34
  %r197 = load i32, ptr %r196, align 4
  %r198 = load i32, ptr @max, align 4
  %r199 = icmp slt i32 %r197, %r198
  br i1 %r199, label %bb37, label %bb38

bb37:                                             ; preds = %bb36
  %r200 = load i32, ptr %r128, align 4
  %r201 = load i32, ptr %r196, align 4
  %r202 = sdiv i32 %r200, %r201
  %r203 = call i32 @mod(i32 %r202, i32 2)
  %r204 = icmp eq i32 %r203, 1
  br i1 %r204, label %bb42, label %bb40

bb42:                                             ; preds = %bb37
  %r205 = load i32, ptr %r130, align 4
  %r206 = load i32, ptr %r196, align 4
  %r207 = sdiv i32 %r205, %r206
  %r208 = call i32 @mod(i32 %r207, i32 2)
  %r209 = icmp eq i32 %r208, 1
  br i1 %r209, label %bb39, label %bb40

bb39:                                             ; preds = %bb42
  %r210 = load i32, ptr %r195, align 4
  %r211 = mul i32 %r210, 2
  %r212 = add i32 %r211, 1
  store i32 %r212, ptr %r195, align 4
  br label %bb41

bb40:                                             ; preds = %bb42, %bb37
  %r213 = load i32, ptr %r195, align 4
  %r214 = mul i32 %r213, 2
  store i32 %r214, ptr %r195, align 4
  br label %bb41

bb41:                                             ; preds = %bb40, %bb39
  %r215 = load i32, ptr %r196, align 4
  %r216 = mul i32 %r215, 2
  store i32 %r216, ptr %r196, align 4
  br label %bb36

bb38:                                             ; preds = %bb36
  %r217 = load i32, ptr %r195, align 4
  ret i32 %r217

5:                                                ; No predecessors!
  br label %bb35

bb35:                                             ; preds = %5, %bb26
  ret i32 0
}

define i32 @getvalue(ptr %r218, i32 %r219, i32 %r221, i32 %r223, i32 %r225) {
bb43:
  %r237 = alloca i32, align 4
  %r220 = alloca i32, align 4
  store i32 %r219, ptr %r220, align 4
  %r222 = alloca i32, align 4
  store i32 %r221, ptr %r222, align 4
  %r224 = alloca i32, align 4
  store i32 %r223, ptr %r224, align 4
  %r226 = alloca i32, align 4
  store i32 %r225, ptr %r226, align 4
  %r227 = load i32, ptr %r224, align 4
  %r228 = icmp slt i32 %r227, 0
  br i1 %r228, label %bb44, label %bb48

bb48:                                             ; preds = %bb43
  %r229 = load i32, ptr %r226, align 4
  %r230 = icmp slt i32 %r229, 0
  br i1 %r230, label %bb44, label %bb47

bb47:                                             ; preds = %bb48
  %r231 = load i32, ptr %r224, align 4
  %r232 = load i32, ptr %r220, align 4
  %r233 = icmp sge i32 %r231, %r232
  br i1 %r233, label %bb44, label %bb46

bb46:                                             ; preds = %bb47
  %r234 = load i32, ptr %r226, align 4
  %r235 = load i32, ptr %r222, align 4
  %r236 = icmp sge i32 %r234, %r235
  br i1 %r236, label %bb44, label %bb45

bb44:                                             ; preds = %bb46, %bb47, %bb48, %bb43
  ret i32 0

0:                                                ; No predecessors!
  br label %bb45

bb45:                                             ; preds = %0, %bb46
  %r238 = load i32, ptr %r224, align 4
  %r239 = load i32, ptr %r222, align 4
  %r240 = mul i32 %r238, %r239
  %r241 = load i32, ptr %r226, align 4
  %r242 = add i32 %r240, %r241
  store i32 %r242, ptr %r237, align 4
  %r243 = load i32, ptr %r237, align 4
  %r244 = getelementptr i32, ptr %r218, i32 %r243
  %r245 = load i32, ptr %r244, align 4
  ret i32 %r245
}

define i32 @convn(i32 %r246, ptr %r248, ptr %r249, i32 %r250, i32 %r252, i32 %r254) {
bb49:
  %r306 = alloca i32, align 4
  %r247 = alloca i32, align 4
  store i32 %r246, ptr %r247, align 4
  %r251 = alloca i32, align 4
  store i32 %r250, ptr %r251, align 4
  %r253 = alloca i32, align 4
  store i32 %r252, ptr %r253, align 4
  %r255 = alloca i32, align 4
  store i32 %r254, ptr %r255, align 4
  %r256 = alloca i32, align 4
  store i32 0, ptr %r256, align 4
  %r257 = alloca i32, align 4
  store i32 0, ptr %r257, align 4
  %r258 = alloca i32, align 4
  %r259 = alloca i32, align 4
  %r260 = alloca i32, align 4
  %r261 = alloca i32, align 4
  store i32 1, ptr %r261, align 4
  br label %bb50

bb50:                                             ; preds = %bb69, %bb49
  %r262 = load i32, ptr %r261, align 4
  %r263 = load i32, ptr %r261, align 4
  %r264 = icmp eq i32 %r262, %r263
  br i1 %r264, label %bb51, label %bb52

bb51:                                             ; preds = %bb50
  store i32 0, ptr %r257, align 4
  br label %bb53

bb53:                                             ; preds = %bb67, %bb51
  %r265 = load i32, ptr %r261, align 4
  %r266 = load i32, ptr %r261, align 4
  %r267 = icmp eq i32 %r265, %r266
  br i1 %r267, label %bb54, label %bb55

bb54:                                             ; preds = %bb53
  store i32 0, ptr %r260, align 4
  %r268 = load i32, ptr %r256, align 4
  %r269 = load i32, ptr %r255, align 4
  %r270 = sdiv i32 %r269, 2
  %r271 = sub i32 %r268, %r270
  store i32 %r271, ptr %r258, align 4
  br label %bb56

bb56:                                             ; preds = %bb65, %bb54
  %r272 = load i32, ptr %r261, align 4
  %r273 = load i32, ptr %r261, align 4
  %r274 = icmp eq i32 %r272, %r273
  br i1 %r274, label %bb57, label %bb58

bb57:                                             ; preds = %bb56
  %r275 = load i32, ptr %r257, align 4
  %r276 = load i32, ptr %r255, align 4
  %r277 = sdiv i32 %r276, 2
  %r278 = sub i32 %r275, %r277
  store i32 %r278, ptr %r259, align 4
  br label %bb59

bb59:                                             ; preds = %bb63, %bb57
  %r279 = load i32, ptr %r261, align 4
  %r280 = load i32, ptr %r261, align 4
  %r281 = icmp eq i32 %r279, %r280
  br i1 %r281, label %bb60, label %bb61

bb60:                                             ; preds = %bb59
  %r282 = load i32, ptr %r247, align 4
  %r283 = load i32, ptr %r260, align 4
  %r284 = load i32, ptr %r251, align 4
  %r285 = load i32, ptr %r253, align 4
  %r286 = load i32, ptr %r258, align 4
  %r287 = load i32, ptr %r259, align 4
  %r288 = call i32 @getvalue(ptr %r248, i32 %r284, i32 %r285, i32 %r286, i32 %r287)
  %r289 = call i32 @reduce(i32 %r282, i32 %r283, i32 %r288)
  store i32 %r289, ptr %r260, align 4
  %r290 = load i32, ptr %r259, align 4
  %r291 = add i32 %r290, 1
  store i32 %r291, ptr %r259, align 4
  %r292 = load i32, ptr %r259, align 4
  %r293 = load i32, ptr %r257, align 4
  %r294 = load i32, ptr %r255, align 4
  %r295 = sdiv i32 %r294, 2
  %r296 = add i32 %r293, %r295
  %r297 = icmp sge i32 %r292, %r296
  br i1 %r297, label %bb62, label %bb63

bb62:                                             ; preds = %bb60
  br label %bb61

0:                                                ; No predecessors!
  br label %bb63

bb63:                                             ; preds = %0, %bb60
  br label %bb59

bb61:                                             ; preds = %bb62, %bb59
  %r298 = load i32, ptr %r258, align 4
  %r299 = add i32 %r298, 1
  store i32 %r299, ptr %r258, align 4
  %r300 = load i32, ptr %r258, align 4
  %r301 = load i32, ptr %r256, align 4
  %r302 = load i32, ptr %r255, align 4
  %r303 = sdiv i32 %r302, 2
  %r304 = add i32 %r301, %r303
  %r305 = icmp sge i32 %r300, %r304
  br i1 %r305, label %bb64, label %bb65

bb64:                                             ; preds = %bb61
  br label %bb58

1:                                                ; No predecessors!
  br label %bb65

bb65:                                             ; preds = %1, %bb61
  br label %bb56

bb58:                                             ; preds = %bb64, %bb56
  %r307 = load i32, ptr %r256, align 4
  %r308 = load i32, ptr %r253, align 4
  %r309 = mul i32 %r307, %r308
  %r310 = load i32, ptr %r257, align 4
  %r311 = add i32 %r309, %r310
  store i32 %r311, ptr %r306, align 4
  %r312 = load i32, ptr %r306, align 4
  %r313 = getelementptr i32, ptr %r249, i32 %r312
  %r314 = load i32, ptr %r260, align 4
  store i32 %r314, ptr %r313, align 4
  %r315 = load i32, ptr %r257, align 4
  %r316 = add i32 %r315, 1
  store i32 %r316, ptr %r257, align 4
  %r317 = load i32, ptr %r257, align 4
  %r318 = load i32, ptr %r253, align 4
  %r319 = icmp sge i32 %r317, %r318
  br i1 %r319, label %bb66, label %bb67

bb66:                                             ; preds = %bb58
  br label %bb55

2:                                                ; No predecessors!
  br label %bb67

bb67:                                             ; preds = %2, %bb58
  br label %bb53

bb55:                                             ; preds = %bb66, %bb53
  %r320 = load i32, ptr %r256, align 4
  %r321 = add i32 %r320, 1
  store i32 %r321, ptr %r256, align 4
  %r322 = load i32, ptr %r256, align 4
  %r323 = load i32, ptr %r251, align 4
  %r324 = icmp sge i32 %r322, %r323
  br i1 %r324, label %bb68, label %bb69

bb68:                                             ; preds = %bb55
  br label %bb52

3:                                                ; No predecessors!
  br label %bb69

bb69:                                             ; preds = %3, %bb55
  br label %bb50

bb52:                                             ; preds = %bb68, %bb50
  ret i32 0
}

define void @memmove(ptr %r325, ptr %r326, i32 %r327) {
bb70:
  %r328 = alloca i32, align 4
  store i32 %r327, ptr %r328, align 4
  %r329 = alloca i32, align 4
  store i32 0, ptr %r329, align 4
  br label %bb71

bb71:                                             ; preds = %bb72, %bb70
  %r330 = load i32, ptr %r329, align 4
  %r331 = load i32, ptr %r328, align 4
  %r332 = icmp slt i32 %r330, %r331
  br i1 %r332, label %bb72, label %bb73

bb72:                                             ; preds = %bb71
  %r333 = load i32, ptr %r329, align 4
  %r334 = getelementptr i32, ptr %r325, i32 %r333
  %r335 = load i32, ptr %r329, align 4
  %r336 = getelementptr i32, ptr %r326, i32 %r335
  %r337 = load i32, ptr %r336, align 4
  store i32 %r337, ptr %r334, align 4
  %r338 = load i32, ptr %r329, align 4
  %r339 = add i32 %r338, 1
  store i32 %r339, ptr %r329, align 4
  br label %bb71

bb73:                                             ; preds = %bb71
  ret void
}

define i32 @main() {
bb74:
  %r368 = alloca i32, align 4
  %r366 = alloca i32, align 4
  %r340 = alloca i32, align 4
  %r341 = call i32 @getint()
  store i32 %r341, ptr %r340, align 4
  %r342 = alloca i32, align 4
  %r343 = call i32 @getint()
  store i32 %r343, ptr %r342, align 4
  %r344 = alloca i32, align 4
  %r345 = call i32 @getint()
  store i32 %r345, ptr %r344, align 4
  %r346 = alloca i32, align 4
  %r347 = call i32 @getint()
  store i32 %r347, ptr %r346, align 4
  %r348 = alloca i32, align 4
  store i32 0, ptr %r348, align 4
  br label %bb75

bb75:                                             ; preds = %bb76, %bb74
  %r349 = load i32, ptr %r348, align 4
  %r350 = load i32, ptr %r346, align 4
  %r351 = icmp slt i32 %r349, %r350
  br i1 %r351, label %bb76, label %bb77

bb76:                                             ; preds = %bb75
  %r352 = load i32, ptr %r348, align 4
  %r353 = getelementptr [10000000 x i32], ptr @a, i32 0, i32 %r352
  %r354 = call i32 @getint()
  store i32 %r354, ptr %r353, align 4
  %r355 = load i32, ptr %r348, align 4
  %r356 = add i32 %r355, 1
  store i32 %r356, ptr %r348, align 4
  br label %bb75

bb77:                                             ; preds = %bb75
  %r357 = call i32 @getint()
  store i32 %r357, ptr %r346, align 4
  store i32 0, ptr %r348, align 4
  br label %bb78

bb78:                                             ; preds = %bb79, %bb77
  %r358 = load i32, ptr %r348, align 4
  %r359 = load i32, ptr %r346, align 4
  %r360 = icmp slt i32 %r358, %r359
  br i1 %r360, label %bb79, label %bb80

bb79:                                             ; preds = %bb78
  %r361 = load i32, ptr %r348, align 4
  %r362 = getelementptr [10000 x i32], ptr @kernelid_, i32 0, i32 %r361
  %r363 = call i32 @getint()
  store i32 %r363, ptr %r362, align 4
  %r364 = load i32, ptr %r348, align 4
  %r365 = add i32 %r364, 1
  store i32 %r365, ptr %r348, align 4
  br label %bb78

bb80:                                             ; preds = %bb78
  %r367 = load i32, ptr %r346, align 4
  store i32 %r367, ptr %r366, align 4
  call void @_sysy_starttime(i32 209)
  store i32 0, ptr %r368, align 4
  br label %bb81

bb81:                                             ; preds = %bb82, %bb80
  %r369 = load i32, ptr %r368, align 4
  %r370 = load i32, ptr %r366, align 4
  %r371 = icmp slt i32 %r369, %r370
  br i1 %r371, label %bb82, label %bb83

bb82:                                             ; preds = %bb81
  %r372 = load i32, ptr %r368, align 4
  %r373 = getelementptr [10000 x i32], ptr @kernelid_, i32 0, i32 %r372
  %r374 = load i32, ptr %r373, align 4
  %r375 = load i32, ptr %r342, align 4
  %r376 = load i32, ptr %r344, align 4
  %r377 = load i32, ptr %r340, align 4
  call void @convn(i32 %r374, ptr @a, ptr @b, i32 %r375, i32 %r376, i32 %r377)
  %r378 = load i32, ptr %r342, align 4
  %r379 = load i32, ptr %r344, align 4
  %r380 = mul i32 %r378, %r379
  call void @memmove(ptr @a, ptr @b, i32 %r380)
  %r381 = load i32, ptr %r368, align 4
  %r382 = add i32 %r381, 1
  store i32 %r382, ptr %r368, align 4
  br label %bb81

bb83:                                             ; preds = %bb81
  call void @_sysy_stoptime(i32 312)
  %r383 = load i32, ptr %r342, align 4
  %r384 = load i32, ptr %r344, align 4
  %r385 = mul i32 %r383, %r384
  call void @putarray(i32 %r385, ptr @a)
  ret i32 0
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @before_main() #0 {
  %1 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  br label %2

2:                                                ; preds = %18, %0
  %3 = load i32, ptr %1, align 4
  %4 = icmp slt i32 %3, 1024
  br i1 %4, label %5, label %21

5:                                                ; preds = %2
  %6 = load i32, ptr %1, align 4
  %7 = sext i32 %6 to i64
  %8 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %7
  store i32 0, ptr %8, align 4
  %9 = load i32, ptr %1, align 4
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %10
  store i32 0, ptr %11, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %13
  store i32 0, ptr %14, align 4
  %15 = load i32, ptr %1, align 4
  %16 = sext i32 %15 to i64
  %17 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %16
  store i32 0, ptr %17, align 4
  br label %18

18:                                               ; preds = %5
  %19 = load i32, ptr %1, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %1, align 4
  br label %2, !llvm.loop !5

21:                                               ; preds = %2
  store i32 1, ptr @_sysy_idx, align 4
  ret void
}

; Function Attrs: noinline nounwind ssp uwtable(sync)
define internal void @__GLOBAL_init_65535() #1 section "__TEXT,__StaticInit,regular,pure_instructions" {
  %1 = call i32 @__cxa_atexit(ptr @after_main, ptr null, ptr @__dso_handle) #2
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @after_main() #0 {
  %1 = alloca i32, align 4
  store i32 1, ptr %1, align 4
  br label %2

2:                                                ; preds = %63, %0
  %3 = load i32, ptr %1, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = icmp slt i32 %3, %4
  br i1 %5, label %6, label %66

6:                                                ; preds = %2
  %7 = load ptr, ptr @__stderrp, align 8
  %8 = load i32, ptr %1, align 4
  %9 = sext i32 %8 to i64
  %10 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %9
  %11 = load i32, ptr %10, align 4
  %12 = load i32, ptr %1, align 4
  %13 = sext i32 %12 to i64
  %14 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %13
  %15 = load i32, ptr %14, align 4
  %16 = load i32, ptr %1, align 4
  %17 = sext i32 %16 to i64
  %18 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %17
  %19 = load i32, ptr %18, align 4
  %20 = load i32, ptr %1, align 4
  %21 = sext i32 %20 to i64
  %22 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %21
  %23 = load i32, ptr %22, align 4
  %24 = load i32, ptr %1, align 4
  %25 = sext i32 %24 to i64
  %26 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %25
  %27 = load i32, ptr %26, align 4
  %28 = load i32, ptr %1, align 4
  %29 = sext i32 %28 to i64
  %30 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %29
  %31 = load i32, ptr %30, align 4
  %32 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %7, ptr noundef @.str.5, i32 noundef %11, i32 noundef %15, i32 noundef %19, i32 noundef %23, i32 noundef %27, i32 noundef %31)
  %33 = load i32, ptr %1, align 4
  %34 = sext i32 %33 to i64
  %35 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr @_sysy_us, align 4
  %38 = add nsw i32 %37, %36
  store i32 %38, ptr @_sysy_us, align 4
  %39 = load i32, ptr %1, align 4
  %40 = sext i32 %39 to i64
  %41 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %40
  %42 = load i32, ptr %41, align 4
  %43 = load i32, ptr @_sysy_s, align 4
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr @_sysy_s, align 4
  %45 = load i32, ptr @_sysy_us, align 4
  %46 = srem i32 %45, 1000000
  store i32 %46, ptr @_sysy_us, align 4
  %47 = load i32, ptr %1, align 4
  %48 = sext i32 %47 to i64
  %49 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %48
  %50 = load i32, ptr %49, align 4
  %51 = load i32, ptr @_sysy_m, align 4
  %52 = add nsw i32 %51, %50
  store i32 %52, ptr @_sysy_m, align 4
  %53 = load i32, ptr @_sysy_s, align 4
  %54 = srem i32 %53, 60
  store i32 %54, ptr @_sysy_s, align 4
  %55 = load i32, ptr %1, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = load i32, ptr @_sysy_h, align 4
  %60 = add nsw i32 %59, %58
  store i32 %60, ptr @_sysy_h, align 4
  %61 = load i32, ptr @_sysy_m, align 4
  %62 = srem i32 %61, 60
  store i32 %62, ptr @_sysy_m, align 4
  br label %63

63:                                               ; preds = %6
  %64 = load i32, ptr %1, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %1, align 4
  br label %2, !llvm.loop !7

66:                                               ; preds = %2
  %67 = load ptr, ptr @__stderrp, align 8
  %68 = load i32, ptr @_sysy_h, align 4
  %69 = load i32, ptr @_sysy_m, align 4
  %70 = load i32, ptr @_sysy_s, align 4
  %71 = load i32, ptr @_sysy_us, align 4
  %72 = call i32 (ptr, ptr, ...) @fprintf(ptr noundef %67, ptr noundef @.str.6, i32 noundef %68, i32 noundef %69, i32 noundef %70, i32 noundef %71)
  ret void
}

; Function Attrs: nounwind
declare i32 @__cxa_atexit(ptr, ptr, ptr) #2

declare i32 @fprintf(ptr noundef, ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define i32 @getint() #0 {
  %1 = alloca i32, align 4
  %2 = call i32 (ptr, ...) @scanf(ptr noundef @.str, ptr noundef %1)
  %3 = load i32, ptr %1, align 4
  ret i32 %3
}

declare i32 @scanf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define i32 @getch() #0 {
  %1 = alloca i8, align 1
  %2 = call i32 (ptr, ...) @scanf(ptr noundef @.str.1, ptr noundef %1)
  %3 = load i8, ptr %1, align 1
  %4 = sext i8 %3 to i32
  ret i32 %4
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putint(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str, i32 noundef %3)
  ret void
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putch(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, i32 noundef %3)
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @putarray(i32 noundef %0, ptr noundef %1) #0 {
  %3 = alloca i32, align 4
  %4 = alloca ptr, align 8
  %5 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  store ptr %1, ptr %4, align 8
  %6 = load i32, ptr %3, align 4
  %7 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, i32 noundef %6)
  store i32 0, ptr %5, align 4
  br label %8

8:                                                ; preds = %19, %2
  %9 = load i32, ptr %5, align 4
  %10 = load i32, ptr %3, align 4
  %11 = icmp slt i32 %9, %10
  br i1 %11, label %12, label %22

12:                                               ; preds = %8
  %13 = load ptr, ptr %4, align 8
  %14 = load i32, ptr %5, align 4
  %15 = sext i32 %14 to i64
  %16 = getelementptr inbounds i32, ptr %13, i64 %15
  %17 = load i32, ptr %16, align 4
  %18 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, i32 noundef %17)
  br label %19

19:                                               ; preds = %12
  %20 = load i32, ptr %5, align 4
  %21 = add nsw i32 %20, 1
  store i32 %21, ptr %5, align 4
  br label %8, !llvm.loop !8

22:                                               ; preds = %8
  %23 = call i32 (ptr, ...) @printf(ptr noundef @.str.4)
  ret void
}

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @_sysy_starttime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = load i32, ptr %2, align 4
  %4 = load i32, ptr @_sysy_idx, align 4
  %5 = sext i32 %4 to i64
  %6 = getelementptr inbounds [1024 x i32], ptr @_sysy_l1, i64 0, i64 %5
  store i32 %3, ptr %6, align 4
  %7 = call i32 @gettimeofday(ptr noundef @_sysy_start, ptr noundef null)
  ret void
}

declare i32 @gettimeofday(ptr noundef, ptr noundef) #3

; Function Attrs: noinline nounwind optnone ssp uwtable(sync)
define void @_sysy_stoptime(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  %3 = call i32 @gettimeofday(ptr noundef @_sysy_end, ptr noundef null)
  %4 = load i32, ptr %2, align 4
  %5 = load i32, ptr @_sysy_idx, align 4
  %6 = sext i32 %5 to i64
  %7 = getelementptr inbounds [1024 x i32], ptr @_sysy_l2, i64 0, i64 %6
  store i32 %4, ptr %7, align 4
  %8 = load i64, ptr @_sysy_end, align 8
  %9 = load i64, ptr @_sysy_start, align 8
  %10 = sub nsw i64 %8, %9
  %11 = mul nsw i64 1000000, %10
  %12 = load i32, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_end, i32 0, i32 1), align 8
  %13 = sext i32 %12 to i64
  %14 = add nsw i64 %11, %13
  %15 = load i32, ptr getelementptr inbounds (%struct.timeval, ptr @_sysy_start, i32 0, i32 1), align 8
  %16 = sext i32 %15 to i64
  %17 = sub nsw i64 %14, %16
  %18 = load i32, ptr @_sysy_idx, align 4
  %19 = sext i32 %18 to i64
  %20 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %19
  %21 = load i32, ptr %20, align 4
  %22 = sext i32 %21 to i64
  %23 = add nsw i64 %22, %17
  %24 = trunc i64 %23 to i32
  store i32 %24, ptr %20, align 4
  %25 = load i32, ptr @_sysy_idx, align 4
  %26 = sext i32 %25 to i64
  %27 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %26
  %28 = load i32, ptr %27, align 4
  %29 = sdiv i32 %28, 1000000
  %30 = load i32, ptr @_sysy_idx, align 4
  %31 = sext i32 %30 to i64
  %32 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %31
  %33 = load i32, ptr %32, align 4
  %34 = add nsw i32 %33, %29
  store i32 %34, ptr %32, align 4
  %35 = load i32, ptr @_sysy_idx, align 4
  %36 = sext i32 %35 to i64
  %37 = getelementptr inbounds [1024 x i32], ptr @_sysy_us, i64 0, i64 %36
  %38 = load i32, ptr %37, align 4
  %39 = srem i32 %38, 1000000
  store i32 %39, ptr %37, align 4
  %40 = load i32, ptr @_sysy_idx, align 4
  %41 = sext i32 %40 to i64
  %42 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %41
  %43 = load i32, ptr %42, align 4
  %44 = sdiv i32 %43, 60
  %45 = load i32, ptr @_sysy_idx, align 4
  %46 = sext i32 %45 to i64
  %47 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %46
  %48 = load i32, ptr %47, align 4
  %49 = add nsw i32 %48, %44
  store i32 %49, ptr %47, align 4
  %50 = load i32, ptr @_sysy_idx, align 4
  %51 = sext i32 %50 to i64
  %52 = getelementptr inbounds [1024 x i32], ptr @_sysy_s, i64 0, i64 %51
  %53 = load i32, ptr %52, align 4
  %54 = srem i32 %53, 60
  store i32 %54, ptr %52, align 4
  %55 = load i32, ptr @_sysy_idx, align 4
  %56 = sext i32 %55 to i64
  %57 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %56
  %58 = load i32, ptr %57, align 4
  %59 = sdiv i32 %58, 60
  %60 = load i32, ptr @_sysy_idx, align 4
  %61 = sext i32 %60 to i64
  %62 = getelementptr inbounds [1024 x i32], ptr @_sysy_h, i64 0, i64 %61
  %63 = load i32, ptr %62, align 4
  %64 = add nsw i32 %63, %59
  store i32 %64, ptr %62, align 4
  %65 = load i32, ptr @_sysy_idx, align 4
  %66 = sext i32 %65 to i64
  %67 = getelementptr inbounds [1024 x i32], ptr @_sysy_m, i64 0, i64 %66
  %68 = load i32, ptr %67, align 4
  %69 = srem i32 %68, 60
  store i32 %69, ptr %67, align 4
  %70 = load i32, ptr @_sysy_idx, align 4
  %71 = add nsw i32 %70, 1
  store i32 %71, ptr @_sysy_idx, align 4
  ret void
}

attributes #0 = { noinline nounwind optnone ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #1 = { noinline nounwind ssp uwtable(sync) "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }
attributes #2 = { nounwind }
attributes #3 = { "frame-pointer"="non-leaf" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="apple-m1" "target-features"="+aes,+complxnum,+crc,+dotprod,+fp-armv8,+fp16fml,+fullfp16,+jsconv,+lse,+neon,+pauth,+ras,+rcpc,+rdm,+sha2,+sha3,+v8.1a,+v8.2a,+v8.3a,+v8.4a,+v8.5a,+v8a,+zcm,+zcz" }

!llvm.ident = !{!0}
!llvm.module.flags = !{!1, !2, !3, !4}

!0 = !{!"Homebrew clang version 18.1.8"}
!1 = !{i32 1, !"wchar_size", i32 4}
!2 = !{i32 8, !"PIC Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 1}
!4 = !{i32 7, !"frame-pointer", i32 1}
!5 = distinct !{!5, !6}
!6 = !{!"llvm.loop.mustprogress"}
!7 = distinct !{!7, !6}
!8 = distinct !{!8, !6}
