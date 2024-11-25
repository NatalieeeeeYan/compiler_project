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
@que = global [ 1005 x i32 ] zeroinitializer
@h = global i32 0
@tail = global i32 0
@inq = global [ 1005 x i32 ] zeroinitializer
define i32 @quickread( ) {
bb1:
  %r255 = add i32 0, 0
  %r101 = call i32 @getch()
  %r256 = add i32 %r101, 0
  %r257 = add i32 0, 0
  %r258 = add i32 0, 0
  %r259 = add i32 0, 0
  %r260 = add i32 0, 0
  br label %bb_while_5_5_cond

bb_while_5_5_cond:
  %r261 = phi i32 [ %r256, %bb1 ], [ %r269, %bb_if_9_6_end ]
  %r262 = phi i32 [ %r260, %bb1 ], [ %r268, %bb_if_9_6_end ]
  %r105 = icmp slt i32 %r261, 48
  br i1 %r105, label %bb_while_5_5_whilestms, label %bb26_5_next

bb26_5_next:
  %r107 = icmp sgt i32 %r261, 57
  br i1 %r107, label %bb_while_5_5_whilestms, label %bb_while_5_5_bre

bb_while_5_5_whilestms:
  %r109 = icmp eq i32 %r261, 45
  br i1 %r109, label %bb_if_9_6_true, label %bb_if_9_6_false

bb_if_9_6_true:
  %r267 = add i32 1, 0
  br label %bb_if_9_6_end

bb_if_9_6_false:
  br label %bb_if_9_6_end

bb_if_9_6_end:
  %r268 = phi i32 [ %r267, %bb_if_9_6_true ], [ %r262, %bb_if_9_6_false ]
  %r110 = call i32 @getch()
  %r269 = add i32 %r110, 0
  br label %bb_while_5_5_cond

bb_while_5_5_bre:
  br label %bb_while_5_11_cond

bb_while_5_11_cond:
  %r263 = phi i32 [ %r258, %bb_while_5_5_bre ], [ %r265, %bb_while_5_11_whilestms ]
  %r264 = phi i32 [ %r261, %bb_while_5_5_bre ], [ %r266, %bb_while_5_11_whilestms ]
  %r112 = icmp sge i32 %r264, 48
  br i1 %r112, label %bb27_11_next, label %bb_while_5_11_bre

bb27_11_next:
  %r114 = icmp sle i32 %r264, 57
  br i1 %r114, label %bb_while_5_11_whilestms, label %bb_while_5_11_bre

bb_while_5_11_whilestms:
  %r116 = mul i32 %r263, 10
  %r118 = add i32 %r116, %r264
  %r119 = sub i32 %r118, 48
  %r265 = add i32 %r119, 0
  %r120 = call i32 @getch()
  %r266 = add i32 %r120, 0
  br label %bb_while_5_11_cond

bb_while_5_11_bre:
  %r122 = icmp ne i32 %r262, 0
  br i1 %r122, label %bb_if_5_15_true, label %bb_if_5_15_false

bb_if_5_15_true:
  %r124 = sub i32 0, %r263
  ret i32 %r124
bb_if_5_15_false:
  ret i32 %r263
}

define void @addedge( i32 %r126, i32 %r128 ) {
bb2:
  %r272 = add i32 0, 0
  %r273 = add i32 %r126, 0
  %r274 = add i32 0, 0
  %r275 = add i32 %r128, 0
  %r130 = load i32, i32* @cnt
  %r131 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r130
  store i32 %r275, i32* %r131
  %r133 = load i32, i32* @cnt
  %r134 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r133
  %r136 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r273
  %r137 = load i32, i32* %r136
  store i32 %r137, i32* %r134
  %r139 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r273
  %r140 = load i32, i32* @cnt
  store i32 %r140, i32* %r139
  %r141 = load i32, i32* @cnt
  %r142 = add i32 %r141, 1
  store i32 %r142, i32* @cnt
  %r143 = load i32, i32* @cnt
  %r144 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r143
  store i32 %r273, i32* %r144
  %r146 = load i32, i32* @cnt
  %r147 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r146
  %r149 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r275
  %r150 = load i32, i32* %r149
  store i32 %r150, i32* %r147
  %r152 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r275
  %r153 = load i32, i32* @cnt
  store i32 %r153, i32* %r152
  %r154 = load i32, i32* @cnt
  %r155 = add i32 %r154, 1
  store i32 %r155, i32* @cnt
  ret void
}

define void @init( ) {
bb3:
  %r277 = add i32 0, 0
  %r278 = add i32 0, 0
  br label %bb_while_5_46_cond

bb_while_5_46_cond:
  %r279 = phi i32 [ %r278, %bb3 ], [ %r280, %bb_while_5_46_whilestms ]
  %r158 = icmp slt i32 %r279, 1005
  br i1 %r158, label %bb_while_5_46_whilestms, label %bb_while_5_46_bre

bb_while_5_46_whilestms:
  %r160 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r279
  store i32 -1, i32* %r160
  %r162 = add i32 %r279, 1
  %r280 = add i32 %r162, 0
  br label %bb_while_5_46_cond

bb_while_5_46_bre:
  ret void
}

define void @inqueue( i32 %r163 ) {
bb4:
  %r282 = add i32 0, 0
  %r283 = add i32 %r163, 0
  %r166 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r283
  store i32 1, i32* %r166
  %r167 = load i32, i32* @tail
  %r168 = add i32 %r167, 1
  store i32 %r168, i32* @tail
  %r169 = load i32, i32* @tail
  %r170 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r169
  store i32 %r283, i32* %r170
  ret void
}

define i32 @popqueue( ) {
bb5:
  %r172 = load i32, i32* @h
  %r173 = add i32 %r172, 1
  store i32 %r173, i32* @h
  %r285 = add i32 0, 0
  %r175 = load i32, i32* @h
  %r176 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r175
  %r177 = load i32, i32* %r176
  %r286 = add i32 %r177, 0
  %r178 = load i32, i32* @h
  %r179 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r178
  %r180 = load i32, i32* %r179
  ret i32 %r180
}

define i32 @same( i32 %r181, i32 %r183 ) {
bb6:
  %r293 = add i32 0, 0
  %r294 = add i32 %r181, 0
  %r295 = add i32 0, 0
  %r296 = add i32 %r183, 0
  store i32 0, i32* @h
  store i32 0, i32* @tail
  call void @inqueue(i32 %r294)
  %r297 = add i32 0, 0
  %r298 = add i32 0, 0
  %r299 = add i32 0, 0
  %r300 = add i32 0, 0
  %r301 = add i32 0, 0
  %r302 = add i32 0, 0
  %r303 = add i32 0, 0
  %r304 = add i32 0, 0
  br label %bb_while_5_72_cond

bb_while_5_72_cond:
  %r305 = phi i32 [ %r302, %bb6 ], [ %r313, %bb_while_9_78_bre ]
  %r306 = phi i32 [ %r304, %bb6 ], [ %r314, %bb_while_9_78_bre ]
  %r307 = phi i32 [ %r298, %bb6 ], [ %r311, %bb_while_9_78_bre ]
  %r308 = phi i32 [ %r300, %bb6 ], [ %r309, %bb_while_9_78_bre ]
  %r190 = load i32, i32* @h
  %r191 = load i32, i32* @tail
  %r192 = icmp slt i32 %r190, %r191
  br i1 %r192, label %bb_while_5_72_whilestms, label %bb_while_5_72_bre

bb_while_5_72_whilestms:
  %r193 = call i32 @popqueue()
  %r309 = add i32 %r193, 0
  %r196 = icmp eq i32 %r309, %r296
  br i1 %r196, label %bb_if_9_74_true, label %bb_if_9_74_false

bb_if_9_74_true:
  %r310 = add i32 1, 0
  br label %bb_if_9_74_end

bb_if_9_74_false:
  br label %bb_if_9_74_end

bb_if_9_74_end:
  %r311 = phi i32 [ %r310, %bb_if_9_74_true ], [ %r307, %bb_if_9_74_false ]
  %r198 = getelementptr [1005 x i32 ], [1005 x i32 ]* @head, i32 0, i32 %r309
  %r199 = load i32, i32* %r198
  %r312 = add i32 %r199, 0
  br label %bb_while_9_78_cond

bb_while_9_78_cond:
  %r313 = phi i32 [ %r312, %bb_if_9_74_end ], [ %r316, %bb_if_13_80_end ]
  %r314 = phi i32 [ %r306, %bb_if_9_74_end ], [ %r315, %bb_if_13_80_end ]
  %r201 = icmp ne i32 %r313, -1
  br i1 %r201, label %bb_while_9_78_whilestms, label %bb_while_9_78_bre

bb_while_9_78_whilestms:
  %r203 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r313
  %r204 = load i32, i32* %r203
  %r315 = add i32 %r204, 0
  %r206 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r315
  %r207 = load i32, i32* %r206
  %r208 = icmp eq i32 %r207, 0
  br i1 %r208, label %bb_if_13_80_true, label %bb_if_13_80_false

bb_if_13_80_true:
  %r210 = getelementptr [5005 x i32 ], [5005 x i32 ]* @to, i32 0, i32 %r313
  %r211 = load i32, i32* %r210
  call void @inqueue(i32 %r211)
  br label %bb_if_13_80_end

bb_if_13_80_false:
  br label %bb_if_13_80_end

bb_if_13_80_end:
  %r213 = getelementptr [5005 x i32 ], [5005 x i32 ]* @next, i32 0, i32 %r313
  %r214 = load i32, i32* %r213
  %r316 = add i32 %r214, 0
  br label %bb_while_9_78_cond

bb_while_9_78_bre:
  br label %bb_while_5_72_cond

bb_while_5_72_bre:
  %r317 = add i32 0, 0
  br label %bb_while_5_87_cond

bb_while_5_87_cond:
  %r318 = phi i32 [ %r317, %bb_while_5_72_bre ], [ %r321, %bb_while_5_87_whilestms ]
  %r319 = phi i32 [ %r306, %bb_while_5_72_bre ], [ %r320, %bb_while_5_87_whilestms ]
  %r216 = load i32, i32* @tail
  %r217 = icmp sle i32 %r318, %r216
  br i1 %r217, label %bb_while_5_87_whilestms, label %bb_while_5_87_bre

bb_while_5_87_whilestms:
  %r219 = getelementptr [1005 x i32 ], [1005 x i32 ]* @que, i32 0, i32 %r318
  %r220 = load i32, i32* %r219
  %r320 = add i32 %r220, 0
  %r222 = getelementptr [1005 x i32 ], [1005 x i32 ]* @inq, i32 0, i32 %r320
  store i32 0, i32* %r222
  %r224 = add i32 %r318, 1
  %r321 = add i32 %r224, 0
  br label %bb_while_5_87_cond

bb_while_5_87_bre:
  ret i32 %r307
}

define i32 @main( ) {
bb7:
  %r226 = call i32 @quickread()
  store i32 %r226, i32* @n
  %r227 = call i32 @quickread()
  store i32 %r227, i32* @m
  call void @_sysy_starttime(i32 97)
  call void @init()
  %r325 = add i32 0, 0
  %r326 = add i32 0, 0
  %r327 = add i32 0, 0
  %r328 = add i32 0, 0
  %r329 = add i32 0, 0
  %r330 = add i32 0, 0
  br label %bb_while_5_102_cond

bb_while_5_102_cond:
  %r331 = phi i32 [ %r328, %bb7 ], [ %r341, %bb_if_9_107_end ]
  %r332 = phi i32 [ %r330, %bb7 ], [ %r342, %bb_if_9_107_end ]
  %r333 = phi i32 [ %r326, %bb7 ], [ %r335, %bb_if_9_107_end ]
  %r231 = load i32, i32* @m
  %r232 = icmp ne i32 %r231, 0
  br i1 %r232, label %bb_while_5_102_whilestms, label %bb_while_5_102_bre

bb_while_5_102_whilestms:
  %r233 = call i32 @getch()
  %r334 = add i32 %r233, 0
  br label %bb_while_9_104_cond

bb_while_9_104_cond:
  %r335 = phi i32 [ %r334, %bb_while_5_102_whilestms ], [ %r336, %bb_while_9_104_whilestms ]
  %r235 = icmp ne i32 %r335, 81
  br i1 %r235, label %bb31_104_next, label %bb_while_9_104_bre

bb31_104_next:
  %r237 = icmp ne i32 %r335, 85
  br i1 %r237, label %bb_while_9_104_whilestms, label %bb_while_9_104_bre

bb_while_9_104_whilestms:
  %r238 = call i32 @getch()
  %r336 = add i32 %r238, 0
  br label %bb_while_9_104_cond

bb_while_9_104_bre:
  %r240 = icmp eq i32 %r335, 81
  br i1 %r240, label %bb_if_9_107_true, label %bb_if_9_107_false

bb_if_9_107_true:
  %r241 = call i32 @quickread()
  %r337 = add i32 %r241, 0
  %r242 = call i32 @quickread()
  %r338 = add i32 %r242, 0
  %r245 = call i32 @same(i32 %r337, i32 %r338)
  call void @putint(i32 %r245)
  call void @putch(i32 10)
  br label %bb_if_9_107_end

bb_if_9_107_false:
  %r246 = call i32 @quickread()
  %r339 = add i32 %r246, 0
  %r247 = call i32 @quickread()
  %r340 = add i32 %r247, 0
  call void @addedge(i32 %r339, i32 %r340)
  br label %bb_if_9_107_end

bb_if_9_107_end:
  %r341 = phi i32 [ %r337, %bb_if_9_107_true ], [ %r339, %bb_if_9_107_false ]
  %r342 = phi i32 [ %r338, %bb_if_9_107_true ], [ %r340, %bb_if_9_107_false ]
  %r250 = load i32, i32* @m
  %r251 = sub i32 %r250, 1
  store i32 %r251, i32* @m
  br label %bb_while_5_102_cond

bb_while_5_102_bre:
  call void @_sysy_stoptime(i32 117)
  ret i32 0
}

