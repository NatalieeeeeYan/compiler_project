declare i32 @getch( )
declare i32 @getint( )
declare void @putch( i32 )
declare void @putint( i32 )
declare void @putarray( i32, i32* )
declare void @_sysy_starttime( i32 )
declare void @_sysy_stoptime( i32 )
define i32 @main( ) {
bb1:
  %r151 = add i32 0, 0
  %r152 = add i32 0, 0
  %r153 = add i32 0, 0
  %r154 = add i32 0, 0
  %r155 = add i32 0, 0
  %r156 = add i32 0, 0
  %r157 = add i32 0, 0
  call void @_sysy_starttime(i32 3)
  %r158 = add i32 0, 0
  %r159 = add i32 0, 0
  %r102 = alloca [ 10 x i32 ]
  %r160 = add i32 0, 0
  %r161 = add i32 0, 0
  br label %bb_while_5_9_cond

bb_while_5_9_cond:
  %r162 = phi i32 [ %r161, %bb1 ], [ %r163, %bb_while_5_9_whilestms ]
  %r104 = icmp slt i32 %r162, 10
  br i1 %r104, label %bb_while_5_9_whilestms, label %bb_while_5_9_bre

bb_while_5_9_whilestms:
  %r106 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r162
  %r108 = add i32 %r162, 1
  store i32 %r108, i32* %r106
  %r110 = add i32 %r162, 1
  %r163 = add i32 %r110, 0
  br label %bb_while_5_9_cond

bb_while_5_9_bre:
  %r164 = add i32 10, 0
  %r116 = call i32 @getint()
  %r165 = add i32 %r116, 0
  %r118 = sub i32 %r164, 1
  %r166 = add i32 %r118, 0
  %r167 = add i32 0, 0
  %r121 = add i32 %r166, %r167
  %r122 = sdiv i32 %r121, 2
  %r168 = add i32 %r122, 0
  %r169 = add i32 0, 0
  %r170 = add i32 0, 0
  %r171 = add i32 0, 0
  br label %bb_while_5_29_cond

bb_while_5_29_cond:
  %r172 = phi i32 [ %r170, %bb_while_5_9_bre ], [ %r179, %bb_if_9_31_end ]
  %r173 = phi i32 [ %r169, %bb_while_5_9_bre ], [ %r177, %bb_if_9_31_end ]
  %r174 = phi i32 [ %r171, %bb_while_5_9_bre ], [ %r178, %bb_if_9_31_end ]
  %r126 = icmp slt i32 %r172, 10
  br i1 %r126, label %bb22_29_next, label %bb_while_5_29_bre

bb22_29_next:
  %r128 = icmp eq i32 %r173, 0
  br i1 %r128, label %bb_while_5_29_whilestms, label %bb_while_5_29_bre

bb_while_5_29_whilestms:
  %r130 = getelementptr [10 x i32 ], [10 x i32 ]* %r102, i32 0, i32 %r172
  %r131 = load i32, i32* %r130
  %r133 = icmp eq i32 %r131, %r165
  br i1 %r133, label %bb_if_9_31_true, label %bb_if_9_31_false

bb_if_9_31_true:
  %r175 = add i32 1, 0
  %r176 = add i32 %r172, 0
  br label %bb_if_9_31_end

bb_if_9_31_false:
  br label %bb_if_9_31_end

bb_if_9_31_end:
  %r177 = phi i32 [ %r175, %bb_if_9_31_true ], [ %r173, %bb_if_9_31_false ]
  %r178 = phi i32 [ %r176, %bb_if_9_31_true ], [ %r174, %bb_if_9_31_false ]
  %r136 = add i32 %r172, 1
  %r179 = add i32 %r136, 0
  br label %bb_while_5_29_cond

bb_while_5_29_bre:
  %r138 = icmp eq i32 %r173, 1
  br i1 %r138, label %bb_if_5_40_true, label %bb_if_5_40_false

bb_if_5_40_true:
  call void @putint(i32 %r174)
  br label %bb_if_5_40_end

bb_if_5_40_false:
  %r180 = add i32 0, 0
  call void @putint(i32 %r180)
  br label %bb_if_5_40_end

bb_if_5_40_end:
  %r181 = phi i32 [ %r165, %bb_if_5_40_true ], [ %r180, %bb_if_5_40_false ]
  %r182 = add i32 10, 0
  call void @putch(i32 %r182)
  call void @_sysy_stoptime(i32 53)
  ret i32 0
}

