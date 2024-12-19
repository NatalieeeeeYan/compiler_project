declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
@n = global i32 0
@m = global i32 0
@to = global [ 5005 x i32 ] zeroinitializer
@next = global [ 5005 x i32 ] zeroinitializer
@head = global [ 1005 x i32 ] zeroinitializer
@cnt = global i32 0
@vis = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
bb1:
  %r230 = add i32 0, 0
  %r101 = call i32 @getch()
  %r231 = add i32 %r101, 0
  %r232 = add i32 0, 0
  %r233 = add i32 0, 0
  %r234 = add i32 0, 0
  %r235 = add i32 0, 0
  br label %bb_while_5_5_cond

bb_while_5_5_cond:
  %r236 = phi i32 [ %r231, %bb1 ], [ %r244, %bb_if_9_6_end ]
  %r237 = phi i32 [ %r235, %bb1 ], [ %r243, %bb_if_9_6_end ]
  %r105 = icmp slt i32 %r236, 48
  br i1 %r105, label %bb_while_5_5_whilestms, label %bb26_5_next

bb26_5_next:
  %r107 = icmp sgt i32 %r236, 57
  br i1 %r107, label %bb_while_5_5_whilestms, label %bb_while_5_5_bre

bb_while_5_5_whilestms:
  %r109 = icmp eq i32 %r236, 45
  br i1 %r109, label %bb_if_9_6_true, label %bb_if_9_6_false

bb_if_9_6_true:
  %r242 = add i32 1, 0
  br label %bb_if_9_6_end

bb_if_9_6_false:
  br label %bb_if_9_6_end

bb_if_9_6_end:
  %r243 = phi i32 [ %r242, %bb_if_9_6_true ], [ %r237, %bb_if_9_6_false ]
  %r110 = call i32 @getch()
  %r244 = add i32 %r110, 0
  br label %bb_while_5_5_cond

bb_while_5_5_bre:
  br label %bb_while_5_11_cond

bb_while_5_11_cond:
  %r238 = phi i32 [ %r236, %bb_while_5_5_bre ], [ %r241, %bb_while_5_11_whilestms ]
  %r239 = phi i32 [ %r233, %bb_while_5_5_bre ], [ %r240, %bb_while_5_11_whilestms ]
  %r112 = icmp sge i32 %r238, 48
  br i1 %r112, label %bb27_11_next, label %bb_while_5_11_bre

bb27_11_next:
  %r114 = icmp sle i32 %r238, 57
  br i1 %r114, label %bb_while_5_11_whilestms, label %bb_while_5_11_bre

bb_while_5_11_whilestms:
  %r116 = mul i32 %r239, 10
  %r118 = add i32 %r116, %r238
  %r119 = sub i32 %r118, 48
  %r240 = add i32 %r119, 0
  %r120 = call i32 @getch()
  %r241 = add i32 %r120, 0
  br label %bb_while_5_11_cond

bb_while_5_11_bre:
  %r122 = icmp ne i32 %r237, 0
  br i1 %r122, label %bb_if_5_15_true, label %bb_if_5_15_false

bb_if_5_15_true:
  %r124 = sub i32 0, %r239
  ret i32 %r124
bb_if_5_15_false:
  ret i32 %r239
}

define void @addedge( i32 %r126, i32 %r128 ) {
bb2:
  %r247 = add i32 0, 0
  %r248 = add i32 %r126, 0
  %r249 = add i32 0, 0
  %r250 = add i32 %r128, 0
  %r130 = load i32, i32* @cnt
  %r131 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r130
  store i32 %r250, i32* %r131
  %r133 = load i32, i32* @cnt
  %r134 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r133
  %r136 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r248
  %r137 = load i32, i32* %r136
  store i32 %r137, i32* %r134
  %r139 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r248
  %r140 = load i32, i32* @cnt
  store i32 %r140, i32* %r139
  %r141 = load i32, i32* @cnt
  %r142 = add i32 %r141, 1
  store i32 %r142, i32* @cnt
  %r143 = load i32, i32* @cnt
  %r144 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r143
  store i32 %r248, i32* %r144
  %r146 = load i32, i32* @cnt
  %r147 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r146
  %r149 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r250
  %r150 = load i32, i32* %r149
  store i32 %r150, i32* %r147
  %r152 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r250
  %r153 = load i32, i32* @cnt
  store i32 %r153, i32* %r152
  %r154 = load i32, i32* @cnt
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* @cnt
  ret void
}

define void @init( ) {
bb3:
  %r252 = add i32 0, 0
  %r253 = add i32 0, 0
  br label %bb_while_5_43_cond

bb_while_5_43_cond:
  %r254 = phi i32 [ %r253, %bb3 ], [ %r255, %bb_while_5_43_whilestms ]
  %r158 = icmp slt i32 %r254, 1005
  br i1 %r158, label %bb_while_5_43_whilestms, label %bb_while_5_43_bre

bb_while_5_43_whilestms:
  %r160 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r254
  store i32 -1, i32* %r160
  %r162 = add i32 %r254, 1
  %r255 = add i32 %r162, 0
  br label %bb_while_5_43_cond

bb_while_5_43_bre:
  ret void
}

define void @clear( ) {
bb4:
  %r257 = add i32 0, 0
  %r258 = add i32 1, 0
  br label %bb_while_5_51_cond

bb_while_5_51_cond:
  %r259 = phi i32 [ %r258, %bb4 ], [ %r260, %bb_while_5_51_whilestms ]
  %r165 = load i32, i32* @n
  %r166 = icmp sle i32 %r259, %r165
  br i1 %r166, label %bb_while_5_51_whilestms, label %bb_while_5_51_bre

bb_while_5_51_whilestms:
  %r168 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r259
  store i32 0, i32* %r168
  %r170 = add i32 %r259, 1
  %r260 = add i32 %r170, 0
  br label %bb_while_5_51_cond

bb_while_5_51_bre:
  ret void
}

define i32 @same( i32 %r171, i32 %r173 ) {
bb5:
  %r265 = add i32 0, 0
  %r266 = add i32 0, 0
  %r267 = add i32 0, 0
  %r268 = add i32 %r171, 0
  %r269 = add i32 0, 0
  %r270 = add i32 %r173, 0
  %r176 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r268
  store i32 1, i32* %r176
  %r179 = icmp eq i32 %r268, %r270
  br i1 %r179, label %bb_if_5_59_true, label %bb_if_5_59_false

bb_if_5_59_true:
  ret i32 1
bb_if_5_59_false:
  br label %bb_if_5_59_end

bb_if_5_59_end:
  %r182 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r268
  %r183 = load i32, i32* %r182
  %r271 = add i32 %r183, 0
  br label %bb_while_5_63_cond

bb_while_5_63_cond:
  %r272 = phi i32 [ %r265, %bb_if_5_59_end ], [ %r274, %bb_if_9_65_end ]
  %r273 = phi i32 [ %r271, %bb_if_5_59_end ], [ %r275, %bb_if_9_65_end ]
  %r185 = icmp ne i32 %r273, -1
  br i1 %r185, label %bb_while_5_63_whilestms, label %bb_while_5_63_bre

bb_while_5_63_whilestms:
  %r188 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r273
  %r189 = load i32, i32* %r188
  %r274 = add i32 %r189, 0
  %r191 = getelementptr [1005 x i32 ], [1005 x i32 ]* @vis, i32 0, i32 %r274
  %r192 = load i32, i32* %r191
  %r193 = icmp eq i32 %r192, 0
  br i1 %r193, label %bb29_65_next, label %bb_if_9_65_false

bb29_65_next:
  %r196 = call i32 @same(i32 %r274, i32 %r270)
  %r197 = icmp ne i32 %r196, 0
  br i1 %r197, label %bb_if_9_65_true, label %bb_if_9_65_false

bb_if_9_65_true:
  ret i32 1
bb_if_9_65_false:
  br label %bb_if_9_65_end

bb_if_9_65_end:
  %r199 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r273
  %r200 = load i32, i32* %r199
  %r275 = add i32 %r200, 0
  br label %bb_while_5_63_cond

bb_while_5_63_bre:
  ret i32 0
}

define i32 @main( ) {
bb6:
  call void @_sysy_starttime(i32 74)
  %r201 = call i32 @quickread()
  store i32 %r201, i32* @n
  %r202 = call i32 @quickread()
  store i32 %r202, i32* @m
  call void @init()
  %r279 = add i32 0, 0
  %r280 = add i32 0, 0
  %r281 = add i32 0, 0
  %r282 = add i32 0, 0
  %r283 = add i32 0, 0
  %r284 = add i32 0, 0
  br label %bb_while_5_80_cond

bb_while_5_80_cond:
  %r285 = phi i32 [ %r282, %bb6 ], [ %r293, %bb_if_9_85_end ]
  %r286 = phi i32 [ %r284, %bb6 ], [ %r294, %bb_if_9_85_end ]
  %r287 = phi i32 [ %r280, %bb6 ], [ %r289, %bb_if_9_85_end ]
  %r206 = load i32, i32* @m
  %r207 = icmp ne i32 %r206, 0
  br i1 %r207, label %bb_while_5_80_whilestms, label %bb_while_5_80_bre

bb_while_5_80_whilestms:
  %r208 = call i32 @getch()
  %r288 = add i32 %r208, 0
  br label %bb_while_9_82_cond

bb_while_9_82_cond:
  %r289 = phi i32 [ %r288, %bb_while_5_80_whilestms ], [ %r290, %bb_while_9_82_whilestms ]
  %r210 = icmp ne i32 %r289, 81
  br i1 %r210, label %bb31_82_next, label %bb_while_9_82_bre

bb31_82_next:
  %r212 = icmp ne i32 %r289, 85
  br i1 %r212, label %bb_while_9_82_whilestms, label %bb_while_9_82_bre

bb_while_9_82_whilestms:
  %r213 = call i32 @getch()
  %r290 = add i32 %r213, 0
  br label %bb_while_9_82_cond

bb_while_9_82_bre:
  %r215 = icmp eq i32 %r289, 81
  br i1 %r215, label %bb_if_9_85_true, label %bb_if_9_85_false

bb_if_9_85_true:
  %r216 = call i32 @quickread()
  %r291 = add i32 %r216, 0
  %r217 = call i32 @quickread()
  %r292 = add i32 %r217, 0
  call void @clear()
  %r220 = call i32 @same(i32 %r291, i32 %r292)
  call void @putint(i32 %r220)
  call void @putch(i32 10)
  br label %bb_if_9_85_end

bb_if_9_85_false:
  %r221 = call i32 @quickread()
  %r295 = add i32 %r221, 0
  %r222 = call i32 @quickread()
  %r296 = add i32 %r222, 0
  call void @addedge(i32 %r295, i32 %r296)
  br label %bb_if_9_85_end

bb_if_9_85_end:
  %r293 = phi i32 [ %r291, %bb_if_9_85_true ], [ %r295, %bb_if_9_85_false ]
  %r294 = phi i32 [ %r292, %bb_if_9_85_true ], [ %r296, %bb_if_9_85_false ]
  %r225 = load i32, i32* @m
  %r226 = sub i32 %r225, 1
  store i32 %r226, i32* @m
  br label %bb_while_5_80_cond

bb_while_5_80_bre:
  call void @_sysy_stoptime(i32 96)
  ret i32 0
}

