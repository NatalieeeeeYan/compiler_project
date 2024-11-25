declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @Merge( i32* %r100, i32 %r101, i32 %r103, i32 %r105 ) {
bb1:
  %r270 = add i32 0, 0
  %r271 = add i32 0, 0
  %r272 = add i32 %r101, 0
  %r273 = add i32 0, 0
  %r274 = add i32 %r103, 0
  %r275 = add i32 0, 0
  %r276 = add i32 %r105, 0
  %r277 = add i32 0, 0
  %r110 = sub i32 %r274, %r272
  %r111 = add i32 %r110, 1
  %r278 = add i32 %r111, 0
  %r279 = add i32 0, 0
  %r115 = sub i32 %r276, %r274
  %r280 = add i32 %r115, 0
  %r116 = alloca [ 10 x i32 ]
  %r117 = alloca [ 10 x i32 ]
  %r281 = add i32 0, 0
  %r282 = add i32 0, 0
  %r283 = add i32 0, 0
  %r284 = add i32 0, 0
  %r285 = add i32 0, 0
  br label %bb_while_5_15_cond

bb_while_5_15_cond:
  %r286 = phi i32 [ %r285, %bb1 ], [ %r288, %bb_while_5_15_whilestms ]
  %r287 = phi i32 [ %r282, %bb1 ], [ %r289, %bb_while_5_15_whilestms ]
  %r123 = icmp slt i32 %r287, %r278
  br i1 %r123, label %bb_while_5_15_whilestms, label %bb_while_5_15_bre

bb_while_5_15_whilestms:
  %r126 = add i32 %r287, %r272
  %r288 = add i32 %r126, 0
  %r128 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r287
  %r130 = getelementptr i32, i32* %r100, i32 %r288
  %r131 = load i32, i32* %r130
  store i32 %r131, i32* %r128
  %r133 = add i32 %r287, 1
  %r289 = add i32 %r133, 0
  br label %bb_while_5_15_cond

bb_while_5_15_bre:
  br label %bb_while_5_20_cond

bb_while_5_20_cond:
  %r290 = phi i32 [ %r284, %bb_while_5_15_bre ], [ %r293, %bb_while_5_20_whilestms ]
  %r291 = phi i32 [ %r286, %bb_while_5_15_bre ], [ %r292, %bb_while_5_20_whilestms ]
  %r136 = icmp slt i32 %r290, %r280
  br i1 %r136, label %bb_while_5_20_whilestms, label %bb_while_5_20_bre

bb_while_5_20_whilestms:
  %r139 = add i32 %r290, %r274
  %r140 = add i32 %r139, 1
  %r292 = add i32 %r140, 0
  %r142 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r290
  %r144 = getelementptr i32, i32* %r100, i32 %r292
  %r145 = load i32, i32* %r144
  store i32 %r145, i32* %r142
  %r147 = add i32 %r290, 1
  %r293 = add i32 %r147, 0
  br label %bb_while_5_20_cond

bb_while_5_20_bre:
  %r294 = add i32 0, 0
  %r295 = add i32 0, 0
  %r296 = add i32 %r272, 0
  br label %bb_while_5_29_cond

bb_while_5_29_cond:
  %r297 = phi i32 [ %r296, %bb_while_5_20_bre ], [ %r304, %bb_if_9_31_end ]
  %r298 = phi i32 [ %r295, %bb_while_5_20_bre ], [ %r305, %bb_if_9_31_end ]
  %r299 = phi i32 [ %r294, %bb_while_5_20_bre ], [ %r306, %bb_if_9_31_end ]
  %r152 = icmp ne i32 %r299, %r278
  br i1 %r152, label %bb23_29_next, label %bb_while_5_29_bre

bb23_29_next:
  %r155 = icmp ne i32 %r298, %r280
  br i1 %r155, label %bb_while_5_29_whilestms, label %bb_while_5_29_bre

bb_while_5_29_whilestms:
  %r157 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r299
  %r158 = load i32, i32* %r157
  %r160 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r298
  %r161 = load i32, i32* %r160
  %r162 = add i32 %r161, 1
  %r163 = icmp slt i32 %r158, %r162
  br i1 %r163, label %bb_if_9_31_true, label %bb_if_9_31_false

bb_if_9_31_true:
  %r165 = getelementptr i32, i32* %r100, i32 %r297
  %r167 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r299
  %r168 = load i32, i32* %r167
  store i32 %r168, i32* %r165
  %r170 = add i32 %r297, 1
  %r300 = add i32 %r170, 0
  %r172 = add i32 %r299, 1
  %r301 = add i32 %r172, 0
  br label %bb_if_9_31_end

bb_if_9_31_false:
  %r174 = getelementptr i32, i32* %r100, i32 %r297
  %r176 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r298
  %r177 = load i32, i32* %r176
  store i32 %r177, i32* %r174
  %r179 = add i32 %r297, 1
  %r302 = add i32 %r179, 0
  %r181 = add i32 %r298, 1
  %r303 = add i32 %r181, 0
  br label %bb_if_9_31_end

bb_if_9_31_end:
  %r304 = phi i32 [ %r300, %bb_if_9_31_true ], [ %r302, %bb_if_9_31_false ]
  %r305 = phi i32 [ %r298, %bb_if_9_31_true ], [ %r303, %bb_if_9_31_false ]
  %r306 = phi i32 [ %r301, %bb_if_9_31_true ], [ %r299, %bb_if_9_31_false ]
  br label %bb_while_5_29_cond

bb_while_5_29_bre:
  br label %bb_while_5_42_cond

bb_while_5_42_cond:
  %r307 = phi i32 [ %r297, %bb_while_5_29_bre ], [ %r309, %bb_while_5_42_whilestms ]
  %r308 = phi i32 [ %r299, %bb_while_5_29_bre ], [ %r310, %bb_while_5_42_whilestms ]
  %r184 = icmp slt i32 %r308, %r278
  br i1 %r184, label %bb_while_5_42_whilestms, label %bb_while_5_42_bre

bb_while_5_42_whilestms:
  %r186 = getelementptr i32, i32* %r100, i32 %r307
  %r188 = getelementptr [10 x i32 ], [10 x i32 ]* %r116, i32 0, i32 %r308
  %r189 = load i32, i32* %r188
  store i32 %r189, i32* %r186
  %r191 = add i32 %r307, 1
  %r309 = add i32 %r191, 0
  %r193 = add i32 %r308, 1
  %r310 = add i32 %r193, 0
  br label %bb_while_5_42_cond

bb_while_5_42_bre:
  br label %bb_while_5_47_cond

bb_while_5_47_cond:
  %r311 = phi i32 [ %r307, %bb_while_5_42_bre ], [ %r313, %bb_while_5_47_whilestms ]
  %r312 = phi i32 [ %r298, %bb_while_5_42_bre ], [ %r314, %bb_while_5_47_whilestms ]
  %r196 = icmp slt i32 %r312, %r280
  br i1 %r196, label %bb_while_5_47_whilestms, label %bb_while_5_47_bre

bb_while_5_47_whilestms:
  %r198 = getelementptr i32, i32* %r100, i32 %r311
  %r200 = getelementptr [10 x i32 ], [10 x i32 ]* %r117, i32 0, i32 %r312
  %r201 = load i32, i32* %r200
  store i32 %r201, i32* %r198
  %r203 = add i32 %r311, 1
  %r313 = add i32 %r203, 0
  %r205 = add i32 %r312, 1
  %r314 = add i32 %r205, 0
  br label %bb_while_5_47_cond

bb_while_5_47_bre:
  ret i32 0
}

define i32 @MergeSort( i32* %r206, i32 %r207, i32 %r209 ) {
bb2:
  %r319 = add i32 0, 0
  %r320 = add i32 0, 0
  %r321 = add i32 0, 0
  %r322 = add i32 %r207, 0
  %r323 = add i32 0, 0
  %r324 = add i32 %r209, 0
  %r213 = icmp slt i32 %r322, %r324
  br i1 %r213, label %bb_if_5_57_true, label %bb_if_5_57_false

bb_if_5_57_true:
  %r217 = add i32 %r322, %r324
  %r218 = sdiv i32 %r217, 2
  %r325 = add i32 %r218, 0
  %r222 = call i32 @MergeSort(i32* %r206, i32 %r322, i32 %r325)
  %r326 = add i32 %r222, 0
  %r224 = add i32 %r325, 1
  %r327 = add i32 %r224, 0
  %r227 = call i32 @MergeSort(i32* %r206, i32 %r327, i32 %r324)
  %r328 = add i32 %r227, 0
  %r231 = call i32 @Merge(i32* %r206, i32 %r322, i32 %r325, i32 %r324)
  %r329 = add i32 %r231, 0
  br label %bb_if_5_57_end

bb_if_5_57_false:
  br label %bb_if_5_57_end

bb_if_5_57_end:
  %r330 = phi i32 [ %r325, %bb_if_5_57_true ], [ %r320, %bb_if_5_57_false ]
  %r331 = phi i32 [ %r329, %bb_if_5_57_true ], [ %r319, %bb_if_5_57_false ]
  ret i32 0
}

define i32 @main( ) {
bb3:
  call void @_sysy_starttime(i32 71)
  store i32 10, i32* @n
  %r232 = alloca [ 10 x i32 ]
  %r233 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 0
  store i32 4, i32* %r233
  %r234 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 1
  store i32 3, i32* %r234
  %r235 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 2
  store i32 9, i32* %r235
  %r236 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 3
  store i32 2, i32* %r236
  %r237 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 4
  store i32 0, i32* %r237
  %r238 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 5
  store i32 1, i32* %r238
  %r239 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 6
  store i32 6, i32* %r239
  %r240 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 7
  store i32 5, i32* %r240
  %r241 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 8
  store i32 7, i32* %r241
  %r242 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 9
  store i32 8, i32* %r242
  %r334 = add i32 0, 0
  %r335 = add i32 0, 0
  %r336 = add i32 0, 0
  %r245 = load i32, i32* @n
  %r246 = sub i32 %r245, 1
  %r337 = add i32 %r246, 0
  %r247 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 0
  %r250 = call i32 @MergeSort(i32* %r247, i32 %r335, i32 %r337)
  %r338 = add i32 %r250, 0
  br label %bb_while_5_81_cond

bb_while_5_81_cond:
  %r339 = phi i32 [ %r337, %bb3 ], [ %r342, %bb_while_5_81_whilestms ]
  %r340 = phi i32 [ %r338, %bb3 ], [ %r343, %bb_while_5_81_whilestms ]
  %r252 = load i32, i32* @n
  %r253 = icmp slt i32 %r340, %r252
  br i1 %r253, label %bb_while_5_81_whilestms, label %bb_while_5_81_bre

bb_while_5_81_whilestms:
  %r255 = getelementptr [10 x i32 ], [10 x i32 ]* %r232, i32 0, i32 %r340
  %r256 = load i32, i32* %r255
  %r341 = add i32 %r256, 0
  call void @putint(i32 %r341)
  %r342 = add i32 10, 0
  call void @putch(i32 %r342)
  %r260 = add i32 %r340, 1
  %r343 = add i32 %r260, 0
  br label %bb_while_5_81_cond

bb_while_5_81_bre:
  call void @_sysy_stoptime(i32 97)
  ret i32 0
}

