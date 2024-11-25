declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
define i32 @swap( i32* %r100, i32 %r101, i32 %r103 ) {
bb1:
  %r222 = add i32 0, 0
  %r223 = add i32 %r101, 0
  %r224 = add i32 0, 0
  %r225 = add i32 %r103, 0
  %r226 = add i32 0, 0
  %r107 = getelementptr i32, i32* %r100, i32 %r223
  %r108 = load i32, i32* %r107
  %r227 = add i32 %r108, 0
  %r110 = getelementptr i32, i32* %r100, i32 %r223
  %r112 = getelementptr i32, i32* %r100, i32 %r225
  %r113 = load i32, i32* %r112
  store i32 %r113, i32* %r110
  %r115 = getelementptr i32, i32* %r100, i32 %r225
  store i32 %r227, i32* %r115
  ret i32 0
}

define i32 @heap_ajust( i32* %r117, i32 %r118, i32 %r120 ) {
bb2:
  %r233 = add i32 0, 0
  %r234 = add i32 0, 0
  %r235 = add i32 %r118, 0
  %r236 = add i32 0, 0
  %r237 = add i32 %r120, 0
  %r238 = add i32 0, 0
  %r239 = add i32 %r235, 0
  %r240 = add i32 0, 0
  %r126 = mul i32 %r239, 2
  %r127 = add i32 %r126, 1
  %r241 = add i32 %r127, 0
  br label %bb_while_5_14_cond

bb_while_5_14_cond:
  %r242 = phi i32 [ %r239, %bb2 ], [ %r249, %bb_if_9_17_end ]
  %r243 = phi i32 [ %r241, %bb2 ], [ %r250, %bb_if_9_17_end ]
  %r244 = phi i32 [ %r233, %bb2 ], [ %r245, %bb_if_9_17_end ]
  %r130 = add i32 %r237, 1
  %r131 = icmp slt i32 %r243, %r130
  br i1 %r131, label %bb_while_5_14_whilestms, label %bb_while_5_14_bre

bb_while_5_14_whilestms:
  %r134 = add i32 %r243, 1
  %r245 = add i32 %r134, 0
  %r137 = icmp slt i32 %r243, %r237
  br i1 %r137, label %bb29_15_next, label %bb_if_9_15_false

bb29_15_next:
  %r139 = getelementptr i32, i32* %r117, i32 %r243
  %r140 = load i32, i32* %r139
  %r142 = getelementptr i32, i32* %r117, i32 %r245
  %r143 = load i32, i32* %r142
  %r144 = icmp slt i32 %r140, %r143
  br i1 %r144, label %bb_if_9_15_true, label %bb_if_9_15_false

bb_if_9_15_true:
  %r146 = add i32 %r243, 1
  %r246 = add i32 %r146, 0
  br label %bb_if_9_15_end

bb_if_9_15_false:
  br label %bb_if_9_15_end

bb_if_9_15_end:
  %r247 = phi i32 [ %r246, %bb_if_9_15_true ], [ %r243, %bb_if_9_15_false ]
  %r148 = getelementptr i32, i32* %r117, i32 %r242
  %r149 = load i32, i32* %r148
  %r151 = getelementptr i32, i32* %r117, i32 %r247
  %r152 = load i32, i32* %r151
  %r153 = icmp sgt i32 %r149, %r152
  br i1 %r153, label %bb_if_9_17_true, label %bb_if_9_17_false

bb_if_9_17_true:
  ret i32 0
bb_if_9_17_false:
  %r156 = call i32 @swap(i32* %r117, i32 %r242, i32 %r247)
  %r248 = add i32 %r156, 0
  %r249 = add i32 %r247, 0
  %r159 = mul i32 %r249, 2
  %r160 = add i32 %r159, 1
  %r250 = add i32 %r160, 0
  br label %bb_if_9_17_end

bb_if_9_17_end:
  br label %bb_while_5_14_cond

bb_while_5_14_bre:
  ret i32 0
}

define i32 @heap_sort( i32* %r161, i32 %r162 ) {
bb3:
  %r255 = add i32 0, 0
  %r256 = add i32 0, 0
  %r257 = add i32 %r162, 0
  %r258 = add i32 0, 0
  %r259 = add i32 0, 0
  %r167 = sdiv i32 %r257, 2
  %r168 = sub i32 %r167, 1
  %r260 = add i32 %r168, 0
  br label %bb_while_5_31_cond

bb_while_5_31_cond:
  %r261 = phi i32 [ %r259, %bb3 ], [ %r264, %bb_while_5_31_whilestms ]
  %r262 = phi i32 [ %r260, %bb3 ], [ %r265, %bb_while_5_31_whilestms ]
  %r170 = icmp sgt i32 %r262, -1
  br i1 %r170, label %bb_while_5_31_whilestms, label %bb_while_5_31_bre

bb_while_5_31_whilestms:
  %r172 = sub i32 %r257, 1
  %r263 = add i32 %r172, 0
  %r175 = call i32 @heap_ajust(i32* %r161, i32 %r262, i32 %r263)
  %r264 = add i32 %r175, 0
  %r177 = sub i32 %r262, 1
  %r265 = add i32 %r177, 0
  br label %bb_while_5_31_cond

bb_while_5_31_bre:
  %r179 = sub i32 %r257, 1
  %r266 = add i32 %r179, 0
  br label %bb_while_5_37_cond

bb_while_5_37_cond:
  %r267 = phi i32 [ %r255, %bb_while_5_31_bre ], [ %r270, %bb_while_5_37_whilestms ]
  %r268 = phi i32 [ %r261, %bb_while_5_31_bre ], [ %r273, %bb_while_5_37_whilestms ]
  %r269 = phi i32 [ %r266, %bb_while_5_31_bre ], [ %r274, %bb_while_5_37_whilestms ]
  %r181 = icmp sgt i32 %r269, 0
  br i1 %r181, label %bb_while_5_37_whilestms, label %bb_while_5_37_bre

bb_while_5_37_whilestms:
  %r270 = add i32 0, 0
  %r185 = call i32 @swap(i32* %r161, i32 %r270, i32 %r269)
  %r271 = add i32 %r185, 0
  %r187 = sub i32 %r269, 1
  %r272 = add i32 %r187, 0
  %r190 = call i32 @heap_ajust(i32* %r161, i32 %r270, i32 %r272)
  %r273 = add i32 %r190, 0
  %r192 = sub i32 %r269, 1
  %r274 = add i32 %r192, 0
  br label %bb_while_5_37_cond

bb_while_5_37_bre:
  ret i32 0
}

define i32 @main( ) {
bb4:
  %r277 = add i32 0, 0
  call void @_sysy_starttime(i32 50)
  store i32 10, i32* @n
  %r193 = alloca [ 10 x i32 ]
  %r194 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 0
  store i32 4, i32* %r194
  %r195 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 1
  store i32 3, i32* %r195
  %r196 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 2
  store i32 9, i32* %r196
  %r197 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 3
  store i32 2, i32* %r197
  %r198 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 4
  store i32 0, i32* %r198
  %r199 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 5
  store i32 1, i32* %r199
  %r200 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 6
  store i32 6, i32* %r200
  %r201 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 7
  store i32 5, i32* %r201
  %r202 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 8
  store i32 7, i32* %r202
  %r203 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 9
  store i32 8, i32* %r203
  %r278 = add i32 0, 0
  %r279 = add i32 0, 0
  %r205 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 0
  %r206 = load i32, i32* @n
  %r207 = call i32 @heap_sort(i32* %r205, i32 %r206)
  %r280 = add i32 %r207, 0
  br label %bb_while_5_57_cond

bb_while_5_57_cond:
  %r281 = phi i32 [ %r277, %bb4 ], [ %r284, %bb_while_5_57_whilestms ]
  %r282 = phi i32 [ %r280, %bb4 ], [ %r285, %bb_while_5_57_whilestms ]
  %r209 = load i32, i32* @n
  %r210 = icmp slt i32 %r282, %r209
  br i1 %r210, label %bb_while_5_57_whilestms, label %bb_while_5_57_bre

bb_while_5_57_whilestms:
  %r213 = getelementptr [10 x i32 ], [10 x i32 ]* %r193, i32 0, i32 %r282
  %r214 = load i32, i32* %r213
  %r283 = add i32 %r214, 0
  call void @putint(i32 %r283)
  %r284 = add i32 10, 0
  call void @putch(i32 %r284)
  %r218 = add i32 %r282, 1
  %r285 = add i32 %r218, 0
  br label %bb_while_5_57_cond

bb_while_5_57_bre:
  call void @_sysy_stoptime(i32 66)
  ret i32 0
}

