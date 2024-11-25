declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @canJump( i32* %r100, i32 %r101 ) {
bb1:
  %r182 = add i32 0, 0
  %r183 = add i32 0, 0
  %r184 = add i32 0, 0
  %r110 = alloca [ 10 x i32 ]
  %r185 = add i32 0, 0
  %r186 = add i32 %r101, 0
  %r104 = icmp eq i32 %r186, 1
  br i1 %r104, label %bb_if_5_2_true, label %bb_if_5_2_false

bb_if_5_2_true:
  ret i32 1
bb_if_5_2_false:
  br label %bb_if_5_2_end

bb_if_5_2_end:
  %r105 = getelementptr i32, i32* %r100, i32 0
  %r106 = load i32, i32* %r105
  %r108 = sub i32 %r186, 2
  %r109 = icmp sgt i32 %r106, %r108
  br i1 %r109, label %bb_if_5_6_true, label %bb_if_5_6_false

bb_if_5_6_true:
  ret i32 1
bb_if_5_6_false:
  br label %bb_if_5_6_end

bb_if_5_6_end:
  %r187 = add i32 0, 0
  br label %bb_while_5_13_cond

bb_while_5_13_cond:
  %r188 = phi i32 [ %r187, %bb_if_5_6_end ], [ %r189, %bb_while_5_13_whilestms ]
  %r114 = sub i32 %r186, 1
  %r115 = icmp slt i32 %r188, %r114
  br i1 %r115, label %bb_while_5_13_whilestms, label %bb_while_5_13_bre

bb_while_5_13_whilestms:
  %r117 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r188
  store i32 0, i32* %r117
  %r119 = add i32 %r188, 1
  %r189 = add i32 %r119, 0
  br label %bb_while_5_13_cond

bb_while_5_13_bre:
  %r122 = sub i32 %r186, 1
  %r190 = add i32 %r122, 0
  %r124 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r190
  store i32 1, i32* %r124
  %r126 = sub i32 %r186, 2
  %r191 = add i32 %r126, 0
  br label %bb_while_5_20_cond

bb_while_5_20_cond:
  %r192 = phi i32 [ %r191, %bb_while_5_13_bre ], [ %r202, %bb_while_9_29_bre ]
  %r193 = phi i32 [ %r182, %bb_while_5_13_bre ], [ %r198, %bb_while_9_29_bre ]
  %r194 = phi i32 [ %r190, %bb_while_5_13_bre ], [ %r199, %bb_while_9_29_bre ]
  %r128 = icmp sgt i32 %r192, -1
  br i1 %r128, label %bb_while_5_20_whilestms, label %bb_while_5_20_bre

bb_while_5_20_whilestms:
  %r131 = getelementptr i32, i32* %r100, i32 %r192
  %r132 = load i32, i32* %r131
  %r134 = sub i32 %r186, 1
  %r136 = sub i32 %r134, %r192
  %r137 = icmp slt i32 %r132, %r136
  br i1 %r137, label %bb_if_9_22_true, label %bb_if_9_22_false

bb_if_9_22_true:
  %r139 = getelementptr i32, i32* %r100, i32 %r192
  %r140 = load i32, i32* %r139
  %r195 = add i32 %r140, 0
  br label %bb_if_9_22_end

bb_if_9_22_false:
  %r142 = sub i32 %r186, 1
  %r144 = sub i32 %r142, %r192
  %r196 = add i32 %r144, 0
  br label %bb_if_9_22_end

bb_if_9_22_end:
  %r197 = phi i32 [ %r195, %bb_if_9_22_true ], [ %r196, %bb_if_9_22_false ]
  br label %bb_while_9_29_cond

bb_while_9_29_cond:
  %r198 = phi i32 [ %r197, %bb_if_9_22_end ], [ %r201, %bb_if_13_31_end ]
  %r199 = phi i32 [ %r194, %bb_if_9_22_end ], [ %r200, %bb_if_13_31_end ]
  %r146 = icmp sgt i32 %r198, -1
  br i1 %r146, label %bb_while_9_29_whilestms, label %bb_while_9_29_bre

bb_while_9_29_whilestms:
  %r149 = add i32 %r192, %r198
  %r200 = add i32 %r149, 0
  %r151 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r200
  %r152 = load i32, i32* %r151
  %r153 = icmp ne i32 %r152, 0
  br i1 %r153, label %bb_if_13_31_true, label %bb_if_13_31_false

bb_if_13_31_true:
  %r155 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 %r192
  store i32 1, i32* %r155
  br label %bb_if_13_31_end

bb_if_13_31_false:
  br label %bb_if_13_31_end

bb_if_13_31_end:
  %r157 = sub i32 %r198, 1
  %r201 = add i32 %r157, 0
  br label %bb_while_9_29_cond

bb_while_9_29_bre:
  %r159 = sub i32 %r192, 1
  %r202 = add i32 %r159, 0
  br label %bb_while_5_20_cond

bb_while_5_20_bre:
  %r160 = getelementptr [10 x i32 ], [10 x i32 ]* %r110, i32 0, i32 0
  %r161 = load i32, i32* %r160
  ret i32 %r161
}

define i32 @main( ) {
bb2:
  call void @_sysy_starttime(i32 42)
  %r204 = add i32 0, 0
  %r163 = alloca [ 10 x i32 ]
  %r164 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 0
  store i32 3, i32* %r164
  %r165 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 1
  store i32 3, i32* %r165
  %r166 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 2
  store i32 9, i32* %r166
  %r167 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 3
  store i32 0, i32* %r167
  %r168 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 4
  store i32 0, i32* %r168
  %r169 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 5
  store i32 1, i32* %r169
  %r170 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 6
  store i32 1, i32* %r170
  %r171 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 7
  store i32 5, i32* %r171
  %r172 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 8
  store i32 7, i32* %r172
  %r173 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 9
  store i32 8, i32* %r173
  %r205 = add i32 10, 0
  %r174 = getelementptr [10 x i32 ], [10 x i32 ]* %r163, i32 0, i32 0
  %r176 = call i32 @canJump(i32* %r174, i32 %r205)
  %r206 = add i32 %r176, 0
  call void @_sysy_stoptime(i32 49)
  ret i32 %r206
}

